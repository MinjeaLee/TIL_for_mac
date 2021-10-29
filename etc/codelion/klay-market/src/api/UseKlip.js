import axious from "axios";
import { errors } from "caver-js/packages/caver-core-helpers";

export const getAddress = (setQrvalue) =>{

    axious.post(
        "https://a2a-api.klipwallet.com/v2/a2a/prepare",{
            bapp:{
                name:'KLAY MARKET'
            },
            type: "auth"
        }

    ).then((response) => {
        const { request_key } =  response.data;
        const qrcode = `https://klipwallet.com/?target=/a2a?request_key=${request_key}`
        setQrvalue(qrcode);
        let timerId = setInterval(() => {
            axious.get(`https://a2a-api.klipwallet.com/v2/a2a/result?request_key=${request_key}`).then((res) => {
                if(res.data.result){
                    console.log(`[RESULT] ${JSON.stringify(res.data.result)}`);
                    clearInterval(timerId);
                }
            })
        }, 1000);
    })
}