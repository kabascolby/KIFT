import React, { useEffect } from "react";
import "./App.css";
import axios from "axios";

//import History from "./components/History";
//import Recorder from "./components/Recorder";
import Myna from "./components/Myna";

function App() {
  /*
  useEffect(() => {
    axios.post(`http://10.10.136.5:5000/api/users`).then(res => {
      console.log(res.data);
    });
    axios.get(`http://10.10.136.5:5000/api/users`).then(res => {
      console.log(res.data);
    });
  }, []);
  */

  return (
    <div className="App">
      <Myna />
    </div>
  );
}

export default App;
