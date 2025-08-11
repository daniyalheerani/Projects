import mongoose from 'mongoose';

export const connectDB=async()=> {
    try{
        const conn = await mongoose.connect(process.env.MONGO_URI); 
        console.log(`MongoDB Connected: ${conn.connection.host}`);
        }
    catch(error){
        console.error(`Failed to connect MongoDB:`,error);
        process.exit(1); // Exit the process with failure 1, 0 for success
    }
}