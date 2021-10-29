//restore github
pragma solidity >=0.4.24 <=0.5.6;

contract IKIP17Receiver {
    function onKIP17Received(
        address operator,
        address from,
        uint256 tokenId,
        bytes memory data
    ) public returns (bytes4);
}

contract NFTSimple {
    string public name = "KlayLion";
    string public symbol = "KL";

    mapping(uint256 => address) public tokenOwner;
    mapping(uint256 => string) public tokenURIs;

    mapping(address => uint256[]) private _ownedTokens;
    bytes4 private constant _KIP17_RECEIVED = 0x6745782b;

    function mintWithTokenURI(
        address to,
        uint256 tokenId,
        string memory tokenURI
    ) public returns (bool) {
    
        tokenOwner[tokenId] = to;
        tokenURIs[tokenId] = tokenURI;

        _ownedTokens[to].push(tokenId);

        return true;
    }

    function safeTransferFrom(
        address from,
        address to,
        uint256 tokenId,
        bytes memory _data
    ) public {
        require(from == msg.sender, "from != msg.sender");
        require(
            from == tokenOwner[tokenId],
            "you are not the owner of the token"
        );
        
        _removeTokenFromList(from, tokenId);
        _ownedTokens[to].push(tokenId);
        
        tokenOwner[tokenId] = to;
        
        require(
            _checkOnKIP17Received(from, to, tokenId, _data),
            "KIP17: transfer to non KIP17Receiver implementer"
        );
    }

    function _removeTokenFromList(address from, uint256 tokenId) private {
        /
        uint256 lastTokenIdex = _ownedTokens[from].length - 1;
        for (uint256 i = 0; i < _ownedTokens[from].length; i++) {
            if (tokenId == _ownedTokens[from][i]) {
                _ownedTokens[from][i] = _ownedTokens[from][lastTokenIdex];
                _ownedTokens[from][lastTokenIdex] = tokenId;
                break;
            }
        }
    
        _ownedTokens[from].length--;
    }

    function ownedTokens(address owner) public view returns (uint256[] memory) {
        return _ownedTokens[owner];
    }

    function setTokenUri(uint256 id, string memory uri) public {
        tokenURIs[id] = uri;
    }

    function _checkOnKIP17Received(
        address from,
        address to,
        uint256 tokenId,
        bytes memory _data
    ) internal returns (bool) {
        bool success;
        bytes memory returndata;

        if (!isContract(to)) {
            return true;
        }

        (success, returndata) = to.call(
            abi.encodeWithSelector(
                _KIP17_RECEIVED,
                msg.sender,
                from,
                tokenId,
                _data
            )
        );
        if (
            returndata.length != 0 &&
            abi.decode(returndata, (bytes4)) == _KIP17_RECEIVED
        ) {
            return true;
        }

        return false;
    }

    function isContract(address account) internal view returns (bool) {
        uint256 size;
        assembly {
            size := extcodesize(account)
        }
        return size > 0;
    }
}


contract NFTMarket {
    mapping(uint256 => address) public seller;
    mapping(uint256 => address[]) public SellHistory;   // 팔았던 모든 주소를 저장할 매핑 선언
    mapping(uint256 => address[]) public BuyHistory;    // 샀던 모든 주소를 저장할 매핑 선언
    mapping(uint256 => address[]) public temp;          // 샀거나 판 모든 주소를 저장할 temp 선언
    mapping(uint256 => address[]) public TokenHistory;  // temp를 가공한 이후 값을 저장할 매핑 선언
    

    function buyNFT(uint256 tokenId, address NFT) public payable returns (bool) {
        address payable receiver = address(uint160(seller[tokenId]));
        receiver.transfer(10**16);
        NFTSimple(NFT).safeTransferFrom(address(this),msg.sender,tokenId,"0x00");

        BuyHistory[tokenId].push(address(msg.sender));      // 사는 사람의 주소와 tokenId 값을 buyhistory에 push
        temp[tokenId].push(address(msg.sender));            // 이를 모든 기록을 보여주는 TokenHistory에도 저장할 수 있도록 우선적으로 temp에 저장
        
        return true;
    }

    function ViewTokenHistory(uint256 tokenId) public returns (address[] memory){
        // 토큰 아이디를 인자로 받아 해당 토큰 아이디에 저장된 주소들을 보이도록 함
        for(uint256 i = 0; i < temp[tokenId].length - 1; i++){
            for(uint256 j = i + 1; j < temp[tokenId].length; j++){
                // i, j가 temp의 배열을 돌면서 서로 같은 것이 있으면
                if(temp[tokenId][i] == temp[tokenId][j]){
                    temp[tokenId][i] = 0x0000000000000000000000000000000000000000;
                    // 앞에 것을 더미 주소로 만듬.
                }
            }
        }
        for(uint256 i = 0; i < temp[tokenId].length; i++){
            // temp를 하나하나 체크해 가면서
            if(temp[tokenId][i] != 0x0000000000000000000000000000000000000000){
                // 전에 설정 했던 더미 주소가 아닌 모든 주소를 TokenHistory에 push
                TokenHistory[tokenId].push(temp[tokenId][i]);
            }
        }

        return TokenHistory[tokenId];
        // TokenHistory 반환
    }

    function onKIP17Received(address operator,address from,uint256 tokenId,bytes memory data) public returns (bytes4) {
        seller[tokenId] = from;

        SellHistory[tokenId].push(from);
        // 파는 사람의 주소와 tokenId 값을 Sellhistory에 push
        temp[tokenId].push(from);
        // 이를 모든 기록을 보여주는 TokenHistory에도 저장할 수 있도록 우선적으로 temp에 저장

        return bytes4(keccak256("onKIP17Received(address,address,uint256,bytes)"));
    }
}
    
    

