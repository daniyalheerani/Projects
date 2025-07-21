const mongoose = require('mongoose');

const Task = mongoose.model('Task', new mongoose.Schema({
    title: {type: String, required: true},
    description: {type: String, required: true},
    category: {type: String, required: true},
    completed: {type: Boolean, default: false},
    dueDate: {type: Date, default: null},
    priority:{ type: String, enum: ['low', 'medium', 'high'], default: 'medium'},
    userId: { type: mongoose.Schema.Types.ObjectId, ref: 'User' },
    createdAt: {type: Date, default: Date.now},
})
);

module.exports = Task;