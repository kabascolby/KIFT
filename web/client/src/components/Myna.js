import React, { useEffect, useState } from "react";
import annyang from "annyang";

import recordAudio from "./Recorder";

import Loader from "./Loader";

export default function Listener() {
  const [listening, setListening] = useState(false);

  useEffect(() => {
    // Let's define a command.
    var commands = {
      hello: async function() {
        const msg = new SpeechSynthesisUtterance();
        msg.text = "Yes?";
        speechSynthesis.speak(msg);

        setListening(true);
        const recorder = await recordAudio();
        recorder.start();

        setTimeout(async () => {
          const audio = await recorder.stop();
          audio.play(); //TODO: instead of playing the audio -> to send it to Lamine's api
          setListening(false);
        }, 5000);
      }
    };
    // Add our commands to annyang
    annyang.addCommands(commands);

    // Start listening.
    annyang.start();
  }, []);
  return (
    <div>{listening ? <Loader /> : <div>Say 'Hello' to talk to me</div>}</div>
  );
}
