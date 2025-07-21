const Task = require("../models/task");

// Get all tasks for a user
exports.getTasks = async (req, res) => {
    try {
        const tasks = await Task.find({ userId: req.user._id });
        res.status(200).json(tasks);
    } catch (error) {
        res.status(500).json({ message: "Error fetching tasks" });
    }
};
// Get a single task by ID
exports.getTask = async (req, res) => {
    try {
        const task= await Task.findById(req.params.id);
        if (!task) {
            return res.status(404).json({ message: "Task not found" });
        }
        if (task.userId.toString() !==req.user.id){
            return res.status(403).json ({message:"unauthorized access"});
        }
        res.status(200).json(task);
    } catch (error) {
        res.status(500).json({ message: "Error fetching task" });
    }
};
// Create a new task
exports.createTask = async (req, res) => {
    try{
        const { title, description, category, priority, dueDate } = req.body;
        if (!title || !description || !category) {
            return res.status(400).json({ message: "Title, description, and category are required" });
        }
        const task = new Task({ 
            title, 
            description, 
            category, 
            priority, 
            dueDate, 
            completed: false, 
            userId: req.user._id 
        });
        await task.save();
        res.status(201).json(task);
    }
    catch (error) {
        console.error("FULL ERROR DETAILS:", error);  // Log complete error
        console.error("CRITICAL ERROR:", {
            errorName: error.name,          // e.g., "ValidationError"
            errorMessage: error.message,    // Specific error reason
            errorStack: error.stack,        // Where it failed
            receivedData: req.body          // What was sent
        });
        res.status(500).json({ 
            message: "Error creating task",
            error: error.message,  // Force show error details
            stack: process.env.NODE_ENV === 'development' ? error.stack : null
        });
    }
}

// Update a task
exports.updateTask = async (req, res) => {
    try {
        const task = await Task.findById(req.params.id);
        if (!task) return res.status(404).json({ message: "Task not found" });
        if (task.userId.toString() !== req.user.id) {
        return res.status(403).json({ message: "Unauthorized access" });
        }
        // PUT (full update - requires all fields)
        if (req.method === 'PUT') {
        const { title, description, category } = req.body;
        if (!title || !description || !category) {
            return res.status(400).json({ 
            message: "PUT requires title, description, and category" 
            });
        }}
        // Update only provided fields (works for both PUT/PATCH)
        const updatableFields = ['title', 'description', 'category', 'completed', 'priority', 'dueDate'];
        updatableFields.forEach(field => {
        if (req.body[field] !== undefined) {
            task[field] = req.body[field];
        }
        });
        await task.save();
        res.status(200).json(task);
    } catch (error) {
        res.status(500).json({ message: "Error updating task" });
    }
};

// Delete a task
exports.deleteTask = async (req,res)=>{
    try {
        const task = await Task.findById(req.params.id);
        if (!task) {
            return res.status(404).json({ message: "Task not found" });
        }
        if (task.userId.toString() !== req.user.id) {
            return res.status(403).json({ message: "Unauthorized access" });
        }
        await Task.deleteOne({ _id: req.params.id });
        res.status(200).json({ message: "Task deleted successfully" });
    }
    catch (error) {
        res.status(500).json({ message: "Error deleting task" });
    }
}
