// Klaytn IDE uses solidity 0.4.24, 0.5.6 versions.
//restore github
pragma solidity >=0.4.24 <=0.5.6;

contract  NFTsimple{
    string public name = "Leeminjea";
    string public symbol = "kl";
    // ��ū�� owner�� Ȯ������
    mapping(uint256 => address) public tokenowner;
    // ��ū�� uri�� Ȯ�� ����
    mapping(uint256 => string) public tokenuris;
    
    // owner�� ���� ��ū ����Ʈ�� ������
    mapping(address => uint256[]) private _ownedtokens;
    
    // onKPI17Received bytes value
    bytes4 private constant _KIP17_RECEIVED = 0x6745782b;
    
    // ��ū ����
    function mintwithtokenuri(address to, uint256 tokenid, string memory tokenuri) public returns (bool){
        // to���� ��ū ����
        tokenowner[tokenid] = to;
        tokenuris[tokenid] = tokenuri;
        // add token to list
        _ownedtokens[to].push(tokenid);
    }
    
    // ��ū����(from, to, tokenid)
    // owner�� �ٲ�� �� (from -> to)
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
            // ����Ʈ ��Ʈ��Ʈ�� �ƴϸ� ����
            return true;
        }
        // ����Ʈ ��Ʈ��Ʈ �ϸ� onKPI17Received�� �����ϰ� ��, Ȥ�� ���� ����� ���� ���� �޾ƿͶ�
        (success, returndata) = to.call(abi.encodeWithSelector(_KIP17_RECEIVED, msg.sender, from, tokenid, _data));
        // ���� ���� ���� ������ ���ϰ��� _KIP17_RECEIVED���  return true;
        if(returndata.length != 0 && abi.decode(returndata, (bytes4)) == _KIP17_RECEIVED){
            return true;
        }
        return false;
    }
    
    function isContract(address account) internal view returns (bool){
        uint256 size;
        assembly {size := extcodesize(account)}
        // �ڵ尡 �����ϴ°�?
        return size > 0;
        // �ڵ尡 �ִٸ� true, ����� false
    }
    
    
    
    // owner�� ��ū ����Ʈ ����
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
        // ������ ������� 0.01klay�� ����
        address payable receiver = address(uint256(seller[tokenid]));
        
        // 10 ** 18 peb == 1klay
        // 10 ** 16 pev == 0.01klay
        receiver.transfer(10 ** 16);
        
        NFTsimple(NFTaddress).safetransferfrom(address(this),msg.sender,tokenid, '0x00');
    }
    
    // ������ ��ū�� �޾��� �� , �Ǹ��ڰ� �������� ����ؾ���
    function onKPI17Received(address operateor, address from, uint256 tokenid, bytes memory data) public returns (bytes4){
        seller[tokenid] = from;
        
        
        return bytes4(keccak256("onKIP17Received(address,address,uint256,bytes)"));
    }
    
    
    
}