const router = require("express").Router();
const taskController = require("../controllers/taskController");
const { protect } = require("../middleware/authMiddleware"); // Import middleware

// Apply auth middleware to ALL task routes
router.use(protect);

router.get("/", taskController.getTasks);
router.get("/:id", taskController.getTask); 
router.post("/", taskController.createTask); 
router.put("/:id", taskController.updateTask);
router.patch('/:id', taskController.updateTask);
router.delete("/:id", taskController.deleteTask);

module.exports = router;