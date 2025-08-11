import { Song } from '../models/songModel.js';

export const getAllSongs = async(req, res, next) => {
    try{
        //1=for ascending order: oldest to newest
        //-1=for descending order: newest to oldest
        const songs = await Song.find().sort({createdAt: -1});
        res.status(200).json(songs);
    }
    catch(err){
        next(err);
    }
}

export const getFeaturedSongs = async(req, res, next) => {
    try{
        //fetch 6 random featured songs using mongodb's aggregation pipeline
        const songs = await Song.aggregate([
            { $sample: { size: 6 } }, // Randomly select 6 songs
            {$project: { _id: 1, title: 1, artist: 1, imageUrl: 1, audioUrl:1 } } // Project only necessary fields
        ]);
        res.status(200).json(featuredSongs);
    }
    catch(err){
        next(err);
    }
}

export const getMadeForYouSongs = async(req, res, next) => {
    try{
        // Assuming made-for-you songs are determined by some user-specific logic
        const userId = req.user._id; // Assuming user ID is available in the request
        // Fetch songs made for the user, e.g., based on user preferences or history
        const madeForYouSongs = await Song.find({madeForUser: userId}).sort({createdAt: -1}).limit(4);
        res.status(200).json(madeForYouSongs);
    }
    catch(err){
        next(err);
    }
}

export const getTrendingSongs = async(req, res, next) => {
    try{
        // Assuming trending songs are determined by some criteria, e.g., most played or liked
        const trendingSongs = await Song.find().sort({playCount: -1}).limit(4); // Example: top 10 trending songs
        res.status(200).json(trendingSongs);
    }
    catch(err){
        next(err);
    }
}