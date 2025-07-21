const jwt = require("jsonwebtoken");
const User = require("../models/user"); // Move this to TOP level

exports.protect = async (req, res, next) => {
    try {
    // 1. Get token from header
        const token = req.header("Authorization")?.replace("Bearer ", "");
        if (!token) throw new Error("No token provided");

        // 2. Verify token
        const decoded = jwt.verify(token, process.env.JWT_SECRET);
        if (!decoded.id) throw new Error("Invalid token payload");
        // 3. Find and attach user
        const user = await User.findById(decoded.id).select("-password");
        if (!user) throw new Error("User not found");
        req.user = user; // Attach user to request
        next();
    } 
    catch (error) {
        res.status(401).json({ message: "Not authorized" });
    }
};