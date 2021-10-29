// Klaytn IDE uses solidity 0.4.24, 0.5.6 versions.
//restore github
pragma solidity >=0.4.24 <=0.5.6;

contract  NFTsimple{
    string public name = "Leeminjea";
    string public symbol = "kl";
    // 토큰의 owner를 확인해줌
    mapping(uint256 => address) public tokenowner;
    // 토큰의 uri를 확인 해줌
    mapping(uint256 => string) public tokenuris;
    
    // owner가 가진 토큰 리스트를 보여줌
    mapping(address => uint256[]) private _ownedtokens;
    
    // onKPI17Received bytes value
    bytes4 private constant _KIP17_RECEIVED = 0x6745782b;
    
    // 토큰 발행
    function mintwithtokenuri(address to, uint256 tokenid, string memory tokenuri) public returns (bool){
        // to에게 토큰 발행
        tokenowner[tokenid] = to;
        tokenuris[tokenid] = tokenuri;
        // add token to list
        _ownedtokens[to].push(tokenid);
    }
    
    // 토큰전송(from, to, tokenid)
    // owner가 바뀌는 것 (from -> to)
    function safetransferfrom(address from, address to, uint256 tokenid, bytes memory _data) public {
        require(from == msg.sender, "from != msg.sender");
        require(from == tokenowner[tokenid], "you are not the owner of the token");
        _removetokenFromList(from, tokenid);
        
        _ownedtokens[to].push(tokenid);
        tokenowner[tokenid] = to;
        
        require(_checkOnKPI17Received(from, to, tokenid, _data), "KPI17: transfer to non onKPI17Receiver implementer");
        
    }
    
    function _checkOnKPI17Received(address from, address to, uint256 tokenid, bytes memory _data) internal returns (bool){
        bool success;
        bytes memory returndata;
        
        if(!isContract(to)){
            // 스마트 컨트랙트가 아니면 리턴
            return true;
        }
        // 스마트 컨트랙트 하면 onKPI17Received를 실행하게 됨, 혹시 성공 결과와 리턴 값을 받아와라
        (success, returndata) = to.call(abi.encodeWithSelector(_KIP17_RECEIVED, msg.sender, from, tokenid, _data));
        // 만약 리턴 값이 있으면 리턴값이 _KIP17_RECEIVED라면  return true;
        if(returndata.length != 0 && abi.decode(returndata, (bytes4)) == _KIP17_RECEIVED){
            return true;
        }
        return false;
    }
    
    function isContract(address account) internal view returns (bool){
        uint256 size;
        assembly {size := extcodesize(account)}
        // 코드가 존재하는가?
        return size > 0;
        // 코드가 있다면 true, 없디면 false
    }
    
    
    
    // owner의 토큰 리스트 보기
    function ownedtokens(address owner) public view returns (uint256[] memory){
        return _ownedtokens[owner];
    }
    
    function _removetokenFromList(address from, uint256 tokenid) private{
        uint256 lastindex = _ownedtokens[from].length - 1;
        for(uint256 i = 0; i < _ownedtokens[from].length; i++){
            if(tokenid == _ownedtokens[from][i]){
                uint256 temp = _ownedtokens[from][lastindex];
                _ownedtokens[from][lastindex] = _ownedtokens[from][i];
                _ownedtokens[from][i] = temp;
                break;
            }
        }
        _ownedtokens[from].length--;
    }
    
    function settokenuri(uint256 id, string memory uri) public {
        tokenuris[id] = uri;
    }    
    
}


contract NFTmarket{
    mapping(uint256 => address) public seller;
    
    
    function buyNFT(uint256 tokenid, address NFTaddress) public returns (bool){
        // 구매한 사람한테 0.01klay를 보냄
        address payable receiver = address(uint256(seller[tokenid]));
        
        // 10 ** 18 peb == 1klay
        // 10 ** 16 pev == 0.01klay
        receiver.transfer(10 ** 16);
        
        NFTsimple(NFTaddress).safetransferfrom(address(this),msg.sender,tokenid, '0x00');
    }
    
    // 마켓이 토큰을 받았을 떄 , 판매자가 누구인지 기록해야함
    function onKPI17Received(address operateor, address from, uint256 tokenid, bytes memory data) public returns (bytes4){
        seller[tokenid] = from;
        
        
        return bytes4(keccak256("onKIP17Received(address,address,uint256,bytes)"));
    }
    
    
    
}