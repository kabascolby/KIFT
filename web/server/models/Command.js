const mongoose = require("mongoose");

const CommandSchema = new mongoose.Schema({
  text: {
    type: String,
    required: true
  },
  date: {
    type: Date,
    default: Date.now()
  }
});

const Command = mongoose.model("command", CommandSchema);

module.exports = Command;
