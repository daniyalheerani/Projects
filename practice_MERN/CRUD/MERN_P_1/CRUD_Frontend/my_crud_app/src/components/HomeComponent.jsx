import React, { useEffect } from 'react';
import axios from 'axios';
import { Link} from 'react-router-dom';

function HomeComponent() {

    const [data, setData] = React.useState([]);

    useEffect(() => {
        axios.get('/users')
        .then(res=>setData(res.data))
        .catch(err=>console.log(err));
    }, []);

    const handleDelete = (id) => {
        const confirm= window.confirm("Are you sure you want to delete this user?");
        if(confirm) {
            axios.delete(`/users/${id}`)
        .then(res => {
            console.log(res);
            window.location.reload();
        })
        .catch(err => console.log(err));
    }
    }
    return (
        <div className='d-flex flex-column justify-content-center align-items-center bg-light '>
            <h1>List of Users</h1>
            <div className='w-75 rounded bg-white border shadow p-4'>
                <div className='d-flex justify-content-end'>
                    <Link to ='/create' className='btn btn-success'>Add +</Link>
                </div>
                <table className='table table-bordered table-striped'>
                    <thead>
                        <tr>
                            <th>ID</th>
                            <th>First Name</th>
                            <th>Last Name</th>
                            {/* <th>Email</th>
                            <th>Gender</th>
                            <th>Job</th> */}
                        </tr>
                    </thead>
                    <tbody>
                        {data.map((d,i) => (
                            <tr key={d.id}>
                                <td>{d.id}</td>
                                <td>{d.first_name}</td>
                                <td>{d.last_name}</td>
                                {/* <td>{d.email}</td>
                                <td>{d.job}</td> */}
                                <td>
                                    <Link to={`/read/${d.id}`} className='btn btn-sm btn-info me-2' style={{backgroundColor: '#0F52BA',color: 'white', padding: '3px 8px', borderRadius: '1px',  border: '2px solid #0C4299', boxShadow: "0 4px 8px rgba(15, 82, 186, 0.4)"}}>Read</Link>
                                    <Link to={`/update/${d.id}`} className='btn btn-sm btn-primary me-2' style={{backgroundColor: '#FFBF00',color: 'black', padding: '3px 8px', borderRadius: '1px',  border: "2px solid #CC9900", boxShadow: "0 4px 8px rgba(255, 191, 0, 0.4)",}}>Edit</Link>
                                    <button onClick={e=>handleDelete(d.id)} className='btn btn-sm btn-danger'>Delete</button>
                                </td>
                            </tr>
                        ))}
                    </tbody>
                </table>
            </div>
        </div>
    );
    
}
export default HomeComponent;