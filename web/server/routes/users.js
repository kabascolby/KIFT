const express = require("express");

const router = express.Router();

const userController = require("../controllers/users");

router
  .route("/")
  .get(userController.getUser)
  .post(userController.createUser)
  .put(userController.updateUser)
  .delete(userController.deleteUser);

module.exports = router;
