const User = require("../models/User");
// Note: using `force: true` will drop the table if it already exists

exports.getUsers = async (req, res) => {
  try {
    const users = await User.findAll();
    res.status(200).send(users);
  } catch (err) {
    console.error(err.message);
    res.status(500).send("Server error");
  }
};
exports.createUser = async (req, res) => {
  const ip = req.connection.remoteAddress;
  try {
    // Check if user already exists with the ip given
    const res = await User.findAll({
      where: {
        ip
      }
    });
    // If new user then create user in the database using his ip
    if (!res.length) {
      User.create({
        ip
      });
      console.log(`Created New User with ip of ${ip} `)
    }
  } catch (err) {
    console.error(err.message);
    res.status(500).send("Server error");
  }
};
exports.updateUser = async (req, res) => { };
exports.deleteUser = async (req, res) => { };
