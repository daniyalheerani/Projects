const express= require('express');
const fs=require('fs');
let users = require("./MOCK_DATA.json");
const cors = require('cors');


const app = express();

const PORT = 3001;

app.use(express.json()); // to parse JSON bodies
app.use(express.urlencoded({ extended: false })); // to parse URL-encoded bodies
app.use(cors({origin: 'http://localhost:3000', credentials: true, methods: ['GET', 'POST', 'PATCH', 'DELETE']})); // Enable CORS for the React app

//get all user's data in JSON format
app.get('/users', (req, res) => {
    return res.json(users);
});

//get all user's first names
//map-> by reading each element in the array, it returns a new array with the first names
// app.get('/users',(req,res)=>{
//     const html=`
//     <ul>
//         ${users.map((user)=> `<li>${user.first_name}</li>`).join('')}
//     </ul>
//     `;
//     res.send(html);
// });

// app.get ('/api/users/:id', (req, res) => {
//     const id =Number(req.params.id);
//     const user = users.find((user)=>user.id===id);
//     return res.json(user);
// });

app.post('/users', (req, res) => {
    const body =req.body;
    users.push({...body, id: users.length + 1});
    fs.writeFile('./MOCK_DATA.json', JSON.stringify(users), (err, data) => {
        if (err) {
            return res.status(500).json({ error: "Failed to save user" });
        }
        return res.status(201).json({ status:"success", id: users.length});
    });
});

// app.patch('/api/users/:id', (req, res) => {
//         const id = Number(req.params.id);
//         const user = users.findIndex((user) => user.id === id);
//         if (user === -1) {
//             return res.status(404).json({ error: "User not found" });
//         }
//         const updateUser = { ...users[user], ...req.body };
//         users[user] = updateUser;
//         fs.writeFile('./MOCK_DATA.json', JSON.stringify(users), (err, data) => {
//         return res.json({ status:"success", user});
//         });
// });

// app.delete('/api/users/:id', (req,res)=>{
//         const id = Number(req.params.id);
//         const userIndex = users.findIndex((user) => user.id === id);
//         if (userIndex === -1) {
//             return res.status(404).json({ error: "User not found" });
//         }
// //      const deletedUser = users.splice(userIndex, 1);
//         const deleteUser = users.filter((user) => user.id !== id);
//         fs.writeFile('./MOCK_DATA.json', JSON.stringify(users), (err, data) => {
//         return res.json({ status:"success", deleteUser});
//         });
// });

app.route('/users/:id')

    .get((req, res) => {
        const id = Number(req.params.id);
        const user = users.find((user) => user.id === id);
        if (!user) {
            res.status(404).json({ error: "User not found" });
        }
        return res.json(user);
    })

    .patch((req, res) => {
        const id = Number(req.params.id);
        const userIndex = users.findIndex((user) => user.id === id);
        if (!userIndex=== -1) {
            return res.status(404).json({ error: "User not found" });
        }
        const updateUser = { ...users[userIndex], ...req.body };
        users[userIndex] = updateUser;
        fs.writeFile('./MOCK_DATA.json', JSON.stringify(users), (err, data) => {
            if (err) {
                return res.status(500).json({ error: "Failed to update user" });
            }
        res.json({ status:"success", user: updateUser});
        });
    })

    .delete((req, res) => {
        const id = Number(req.params.id);
        const userIndex = users.findIndex((user) => user.id === id);
        if (userIndex === -1) {
            return res.status(404).json({ error: "User not found" });
        }
//      const deletedUser = users.splice(userIndex, 1);
        const deleteUser = users.filter((user) => user.id !== id);
        fs.writeFile('./MOCK_DATA.json', JSON.stringify(deleteUser), (err, data) => {
            if (err) {
                return res.status(500).json({ error: "Failed to delete user" });
            }
           users = deleteUser; // Update the users array
            res.json({ status:"success", deleteUser});
        });
    });

app.listen(PORT, () => {
    console.log(`Server Started At http://localhost:${PORT}`);
});