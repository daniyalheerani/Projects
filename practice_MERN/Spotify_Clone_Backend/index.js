import express from 'express';
import dotenv from 'dotenv';
import { clerkMiddleware } from '@clerk/express';
import fileUpload from 'express-fileupload';

import { connectDB } from './src/lib/db.js';

import userRoutes from './src/routes/userRoute.js';
import albumRoutes from './src/routes/albumRoute.js';
import songRoutes from './src/routes/songRoute.js';
import statRoutes from './src/routes/statRoute.js';
import authRoutes from './src/routes/authRoute.js';
import adminRoutes from './src/routes/adminRoute.js';

import path from 'path';
import { requireAdmin, protectRoute} from './src/middleware/authMiddleware.js';



dotenv.config();

const __dirname = path.resolve();
const app=express();
const PORT=process.env.PORT;

app.use(express.json());// Parse JSON bodies
app.use(clerkMiddleware());// Populate req.auth via Clerk
app.use(fileUpload({
    useTempFiles: true, // Store files in a temporary directory
    tempFileDir: path.join(__dirname, "tmp"), // Specify the temporary directory
    createParentPath: true, // Create parent directories if they don't exist
    limits:{
        fileSize: 10 * 1024 * 1024, // Limit file size to 10MB
    }
}));

app.use("/api/users", userRoutes, protectRoute);
app.use("/api/auth", authRoutes);
app.use("/api/admin", adminRoutes, requireAdmin, protectRoute);
app.use("/api/songs", songRoutes);
app.use("/api/albums", albumRoutes);
app.use("/api/stats", statRoutes);

//error handling middleware
app.use((err, req, res, next) => {
    console.error("Error:", err);
    res.status(500).json({ message: process.env.NODE_ENV === 'production' ? "Internal Server Error" : err.message });
});

app.listen(PORT, () => {
    console.log(`Server is running on http://localhost:${PORT}`);
    connectDB();
});

//todo: socket.io
