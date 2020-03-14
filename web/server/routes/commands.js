const express = require("express");

const router = express.Router();

const commandController = require("../controllers/commands");

router
  .route("/")
  .get(commandController.getCommands)
  .post(commandController.createCommand)
  .put(commandController.updateCommand)
  .delete(commandController.deleteCommand);

module.exports = router;
