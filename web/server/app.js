const path = require("path");
const express = require("express");
const cors = require("cors");

const app = express();

// Init Middleware to be able to use cors
app.use(cors());
// Init Middleware to be able to use req.body
app.use(express.json());

// Define Routes for RESTFUL API (v1)
const userRoutes = require("./routes/users");
const commandRoutes = require("./routes/commands");

app.use("/api/users", userRoutes);
app.use("/api/commands", commandRoutes);

// Serve static files from the React app
app.use(express.static(path.join(__dirname, "../../frontend/build")));

// The "catchall" handler: for any request that doesn't
// match one above, send back React's index.html file.
app.get("*", (req, res) => {
  res.sendFile(path.join(__dirname, "../../frontend/build/index.html"));
});
module.exports = app;
