require("dotenv").config();
const app = require("./app");
const db = require("./db");

const port = process.env.PORT || 5000;

app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
