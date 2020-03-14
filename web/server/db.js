const config = require("./config");
const mongoose = require("mongoose");

const dbHost = config.db.host;
const dbUser = config.db.user;
const dbPass = config.db.password;
const dbName = config.db.name;

const dbURI = `mongodb+srv://${dbUser}:${dbPass}@${dbHost}/${dbName}?retryWrites=true&w=majority`;

exports.connectDB = async () => {
  try {
    await mongoose.connect(dbURI, {
      useNewUrlParser: true,
      useFindAndModify: false,
      useCreateIndex: true,
      useUnifiedTopology: true
    });

    console.log("MonogoDB connected");
  } catch (err) {
    console.error(err.message);

    // Exit process with failure
    process.exit(1);
  }
};
