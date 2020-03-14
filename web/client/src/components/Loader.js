import React from "react";
import { css } from "@emotion/core";
import ScaleLoader from "react-spinners/ScaleLoader";

// Can be a string as well. Need to ensure each key-value pair ends with ;
const override = css`
  display: block;
  margin: 0 auto;
  border-color: red;
`;

function Loader() {
  return (
    <div className="sweet-loading">
      <ScaleLoader css={override} size={150} color={"#123abc"} loading={true} />
    </div>
  );
}

export default Loader;
