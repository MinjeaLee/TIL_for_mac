import logo from './logo.svg';
import {getBalance, readCount, setCount} from './api/UseCaver';
import './App.css';
import React, {useState} from "react";
import QRcode from "qrcode.react";
import * as klipAPI from "./api/UseKlip";

// ABI(Application Binary Interface) => like instruction
function onPressButton(balance) {
  console.log('hi');
}
const onPressButton2 = (_balance, _setBalance) => {
  _setBalance(_balance);
};

const DEFAULT_QR_CODE = "DEFAULT";
function App() {
  const [balance, setBalance] = useState('0');
  const [qrvalue, setQrvalue] = useState(DEFAULT_QR_CODE);
  // const onPressButton2 = (balance) => {
  //   setBalance('10');
  // }
  // readCount();
  // getBalance('0x398627ff984396ae5e3f36df4dfd33d05dfb48c6');
  const onClickgetAddress = () => {
    klipAPI.getAddress(setQrvalue);
  };  
  return (
    <div className="App">
      <header className="App-header">
        {/* <img src={logo} className="App-logo" alt="logo" /> */}
        {/* <button title={""} onClick={() => {setCount(100)}} /> */}
        {/* <button onClick={() => {onPressButton2('15', setBalance)}}>hi</button> */}
        <button onClick={() =>{
          onClickgetAddress();
        }}>
          ì£¼ì†Œê°?? ¸?˜¤ê¸?
        </button>
        <br/>
        <QRcode value={qrvalue} />
        <p>
          {balance}
          {/* hi <code>src/App.js</code> and save to reload. */}
        </p>
        {/* <a
          className="App-link"
          href="https://reactjs.org"
          target="_blank"
          rel="noopener noreferrer"
        >
          Learn React
        </a> */}
      </header>
    </div>
  );
}

export default App;
