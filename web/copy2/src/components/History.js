import React, { useState, useEffect } from "react";
import axios from "axios";

export default function History() {
  const [history, setHistory] = useState([]);

  useEffect(() => {
    axios.get(`http://localhost:5000/api/commands`).then(res => {
      setHistory(res.data);
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
