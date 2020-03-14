const Command = require("../models/Command");

// @route   GET /commands
// @desc    Get all commands
// @access  Public
exports.getCommands = async (req, res) => {
  try {
    let commands = await Command.find();
    return res.status(200).json(commands);
  } catch (err) {
    console.error(err.message);
    res.status(500).send("Server error");
  }
};

// @route   GET /commands/...???...
// @desc    Get current user's Command by his req.userID
// @access  Public
exports.getMyCommand = async (req, res) => {
  try {
    const Command = await Command.findOne({ user: req.user.id });
    if (!Command) {
      return res.status(400).json({ errors: [{ msg: "Command not found" }] });
    }
    res.json(Command);
  } catch (err) {
    if (err.kind == "ObjectId") {
      return res.status(400).json({ errors: [{ msg: "Command not found" }] });
    }
    console.error(err.message);
    res.status(500).send("Server Error");
  }
};

// @route   GET /Commands/:CommandID
// @desc    Get Command by CommandID
// @access  Private
exports.getCommand = async (req, res) => {
  try {
    const Command = await Command.findById(req.params.CommandID);
    if (!Command) {
      return res.status(400).json({ errors: [{ msg: "Command not found" }] });
    }
    res.json(Command);
  } catch (err) {
    if (err.kind == "ObjectId") {
      return res.status(400).json({ errors: [{ msg: "Command not found" }] });
    }
    console.error(err.message);
    res.status(500).send("Server Error");
  }
};

// @route   POST /Commands
// @desc    Create user's Command
// @access  Private
exports.createCommand = async (req, res) => {
  try {
    let Command = await Command.findOne({ user: req.user.id });
    if (Command) {
      // Return error because Command already exists
      return res.status(401).json({ errors: [{ msg: "Command exists" }] });
    } else {
      // Create
      /*
      const {
        name
      } = req.body;
      */
      Command = new Command({
        user: req.user.id
        //  name
      });
      await Command.save();
    }
    res.json(Command);
  } catch (err) {
    console.error(err.message);
    res.status(500).send("Server error");
  }
};

// @route   PATCH /Commands/:CommandID
// @desc    Update user's Command
// @access  Private
exports.updateCommand = async (req, res) => {
  try {
    let Command = await Command.findById(req.params.CommandID);
    if (!Command) {
      // Return error because Command doesn't exists
      return res
        .status(401)
        .json({ errors: [{ msg: "Command does not exists" }] });
    } else {
      // Update
      Command = await Command.findByIdAndUpdate(
        req.params.CommandID,
        req.body,
        { new: true }
      );
    }
    res.json(Command);
  } catch (err) {
    console.error(err.message);
    res.status(500).send("Server error");
  }
};

// @route   DELETE /Commands/:CommandID
// @desc    Delete Command by CommandID
// @access  Private
exports.deleteCommand = async (req, res) => {
  try {
    // TODO: Make sure that the user has the right access to remove this Command...
    // Remove Command
    await Command.deleteOne({ _id: req.params.CommandID });
    res.json({ msg: "Command deleted" });
  } catch (err) {
    console.error(err.message);
    res.status(500).send("Server Error");
  }
};
