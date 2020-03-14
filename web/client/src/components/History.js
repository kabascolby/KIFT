import React, { useState, useEffect } from "react";
import axios from "axios";

export default function History() {
  const [history, setHistory] = useState([]);

  useEffect(() => {
    axios.get(`http://10.10.136.5:5000/api/commands`).then(res => {
      setHistory(res.data);
      console.log(res.data);
    }).catch(err => {
      console.error(err.message)
    });
  }, []);

  return (
    <div>
      {history.length ? (
        history.map(command => <div>{command.text}</div>)
      ) : (
          <div>No previous commands.</div>
        )}
    </div>
  );
}
