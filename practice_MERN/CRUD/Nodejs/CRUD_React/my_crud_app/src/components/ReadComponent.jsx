import React, {useEffect} from 'react';
import axios from 'axios';
import { Link, useParams } from 'react-router-dom';

function ReadComponent() {

    const [data, setData] = React.useState({
        first_name: '',
        last_name: '',
        email: '',
        gender: '',
        job: ''
    });
    const { id } = useParams(); 

    useEffect(() => {
        axios.get(`/users/${id}`)
        .then(res=>setData(res.data))
        .catch(err=>console.log(err));
    }, [id]);

    if (!data) return <div className='d-flex w-100 vh-100 justify-content-center align-items-center'>Loading...</div>;

    return (
        <div className='d-flex w-100 vh-100 justify-content-center align-items-center bg-light'>
            <div className='w-50 border bg-white shadow px-5 pt-3 pb-5 rounded'>
                <h1>Details of User</h1>
                <div className='mb-2'>
                    <strong>First Name:{data.first_name}</strong> 
                </div>
                <div className='mb-2'>
                    <strong>Last Name:{data.last_name}</strong>
                </div>
                <div className='mb-2'>
                    <strong>Email:{data.email}</strong>
                </div>
                <div className='mb-2'>
                    <strong>Gender:{data.gender}</strong>
                </div>
                <div className='mb-2'>
                    <strong>Job:{data.job}</strong>
                </div>
                <Link to={`/update/${id}`} className='btn btn-success'>Edit</Link>
                <Link to='/' className='btn btn-danger ms-2'>Cancel</Link>
                
            </div>
        </div>
    );
}
export default ReadComponent;