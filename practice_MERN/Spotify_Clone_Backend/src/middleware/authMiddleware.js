import { clerkClient } from "@clerk/express";

export const protectRoute = (req, res, next) => {
    if(!req.auth.userId) {
        return res.status(401).json({ message: "Unauthorized access, Login first." });
    }
    next();
};

export const requireAdmin = async (req, res, next) => {
    try{
        const currentUser = await clerkClient.users.getUser(req.auth.userId);
        const isAdmin = process.env.ADMIN_EMAIL === currentUser.primaryEmailAddress?.emailAddress;
        
        if (!isAdmin) {
            return res.status(403).json({ message: "Access denied, Admins only." });
        }
    }
    catch (error) {
        console.error("Error checking admin status:", error);
        next(error);
    }
};