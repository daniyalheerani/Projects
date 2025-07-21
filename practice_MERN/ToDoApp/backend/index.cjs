require('dotenv').config(); // Load environment variables first
const express = require('express');
const cors = require('cors'); // For cross-origin requests
const morgan = require('morgan'); // HTTP request logger (optional)
const connectDB = require('./database/db.js'); // Database connection
const errorHandler = require('./middleware/errorHandler'); // Custom error handler (optional)

// Import routes
const authRoutes = require('./routes/authRoutes.js');
const taskRoutes = require('./routes/taskRoutes.js');

const app = express();
const PORT = process.env.PORT || 8080;

//handling error
//app.use(errorHandler);

// =====================
//      Middleware
// =====================
app.use(cors()); // Enable CORS
app.use(express.json()); // Parse JSON bodies
app.use(morgan('dev')); // Log requests (remove in production if needed)


app.use('/api/auth', authRoutes);
app.use('/api/tasks', taskRoutes);

// Test route
app.get('/', (req, res) => {
    res.send('To-Do App API is running...');
});


connectDB()
    .then(() => {
        app.listen(PORT, () => {
        console.log(`Server running on port ${PORT}`);
        console.log(`MongoDB connected`);
    });
    })
    .catch((err) => {
        console.error('Database connection failed. Server not started');
        console.error(err);
    }
);