import {Album} from "../models/albumModel.js";
import {Song} from "../models/songModel.js";
import {User} from "../models/userModel.js";


export const getStats= async (req, res, next) => {
    try{
        const [totalAlbums, totalSongs, totalUsers, uniqueArtists] = await Promise.all([
            Song.countDocuments(),
            Album.countDocuments(),
            User.countDocuments(),

            Song.aggregate([
                {$unionWith: {
                    coll: "albums", pipeline: []
                }},
                {
                    $group:{
                        _id: "$artist"
                    }
                },
                {
                    $count: "count"
                },
            ]),
        ]);
        res.status(200).json({
            totalAlbums,
            totalSongs, 
            totalUsers,
            uniqueArtists: uniqueArtists[0]?.count || 0,
        
        });
    }
    catch(error){
        console.error("Error in statRoute:", error);
        next(error);
    } 
};