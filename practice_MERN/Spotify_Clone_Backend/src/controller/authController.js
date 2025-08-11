import { User } from "../models/userModel.js";

export const authCallback = async (req, res, next) => {
    try{
        const {id, firstName, lastName, imageUrl} = req.body;
        // Check if user already exists
        const user= await User.findOne({ clerkId: id });

        if(!user){
            //signup
            await User.create({
                clerkId: id,
                fullName: `${firstName} ${lastName}`,
                imageRrl: imageUrl
            });
        }
        res.status(200).json({ message: "User signed up successfully" });
    }
    catch (error) {
        console.error("Error in callback route:", error);
        next(error);
    }
};