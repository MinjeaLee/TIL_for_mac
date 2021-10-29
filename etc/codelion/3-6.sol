pragma solidity >=0.4.24 <=0.5.6;

contract Practice {
    uint256 private totalSupply = 10;
    string public name = "Leeminjea";
    
    function gettotalsupply() public view returns (uint256){
        return totalSupply + 10;
    }
    function settotalsupply(uint256 newsupply) public{
        totalSupply = newsupply;
    }
    
}