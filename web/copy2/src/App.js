import React from "react";
import "./App.css";

import History from "./components/History";
import Loader from "./components/Loader";

function App() {
  return (
    <div className="App">
      <History />
      <Loader />
    </div>
  );
}

export default App;
