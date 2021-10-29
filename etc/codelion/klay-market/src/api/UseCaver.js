import Caver from 'caver-js';
import CounterABI from '../abi/CounterABI.json';
import {ACCESS_KEY_ID, SECRET_ACCESS_KEY, COUNT_CONTRACT_ADDRESS, CHAIN_ID} from '../constants'
const option = {
    headers: [
        {
          name: "Authorization",
          value: "Basic " + Buffer.from(ACCESS_KEY_ID + ":" + SECRET_ACCESS_KEY).toString("base64")
        },

        {
          name : "x-chain-id",
          value : CHAIN_ID
        }
    ]
}
    
const caver = new Caver(new Caver.providers.HttpProvider("https://node-api.klaytnapi.com/v1/klaytn", option));
const CountContract = new caver.contract(CounterABI, COUNT_CONTRACT_ADDRESS);
    
export const readCount = async () => {
      const _count = await CountContract.methods.count().call();
      console.log(_count);
}
    
export const getBalance = (address) => {
    return caver.rpc.klay.getBalance(address).then((response) => {
        const balance = caver.utils.convertFromPeb(caver.utils.hexToNumberString(response));
        console.log(`balance:${balance}`);
        return balance;
    })
}
    
export const setCount = async (newcount) => {
    try{
        const privatekey = '0x9199189b281fc075076a13fead883935bbd435eaf0c6fc5a27d6ebb1dd3d564c';
        const deployer = caver.wallet.keyring.createFromPrivateKey(privatekey);
        caver.wallet.add(deployer);
      
        const receipt = await CountContract.methods.setCount(newcount).send({
            from: deployer.address,// address
            gas: "0x4bfd20"
        });
        console.log(receipt);
    }catch(e){
        console.log(`[ERROR_SET_COUNT]${e}`);
    }
}