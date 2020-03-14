const Sequelize = require('sequelize');
const config = require("./config");

const dbHost = config.db.host;
const dbUser = config.db.user;
const dbPass = config.db.password;
const dbName = config.db.name;

const sequelize = new Sequelize({
  dialect: 'sqlite',
  storage: './db.sqlite'
});

sequelize
  .authenticate()
  .then(() => {
    console.log('Connection has been established successfully.');
  })
  .catch(err => {
    console.error('Unable to connect to the database:', err);
  });

module.exports = sequelize;