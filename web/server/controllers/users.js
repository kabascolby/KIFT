const User = require("../models/User");

exports.getUser = async (req, res) => {};
exports.createUser = async (req, res) => {
  const { ip } = req.body;

  try {
    // Check if user already exists with the ip given
    let user = await User.findOne({ email });
    if (user) {
      return res
        .status(400)
        .json({ errors: [{ msg: "Email already exists" }] });
    }

    // Create user object
    user = new User({
      email,
      password
    });

    // Add user to the database
    const userSaved = await user.save();
  } catch (err) {
    console.error(err.message);
    res.status(500).send("Server error");
  }
};
exports.updateUser = async (req, res) => {};
exports.deleteUser = async (req, res) => {};
