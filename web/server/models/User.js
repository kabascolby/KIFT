const Sequelize = require('sequelize')
const sequelize = require('../db');

const User = sequelize.define('user', {
  ip: {
    type: Sequelize.STRING
  },
  history: {
    type: Sequelize.JSON
  }
}, {
  // options
});

User.sync({ force: true }).then(() => {
  // Now the `users` table in the database corresponds to the model definition
  return User.create({
    ip: "test",
    history: {
      test: "test"
    }
  });
});

module.exports = User;