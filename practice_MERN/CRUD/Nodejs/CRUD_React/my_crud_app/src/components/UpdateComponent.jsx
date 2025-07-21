import {useEffect, useState} from 'react';
import axios from 'axios';
import { Link, useParams , useNavigate} from 'react-router-dom';

function UpdateComponent() {

    const { id } = useParams(); 

    const [ value, setValue ] = useState({
            first_name: '',
            last_name: '',
            email: '',
            gender: '',
            job: ''
        });
    

    useEffect(() => {
        axios.get(`/users/${id}`)
        .then(res=>{
            setValue(res.data);
        })
        .catch(err=>console.log(err));
    }, [id]);
    const Navigate = useNavigate();
    const handleUpdate = (e) => {
        e.preventDefault();
        axios.patch(`/users/${id}`, value)
        .then(res=>{
            console.log(res);
            Navigate('/');
        })
        .catch(err=>console.log(err));
    }

    return (
        <div className='d-flex w-100 vh-100 justify-content-center align-items-center bg-light'>
            <div className='w-50 border bg-white shadow px-5 pt-3 pb-5 rounded'>
                <h1>Update a User</h1>
                <form onSubmit={handleUpdate}>
                    <div className='mb-2'>
                        <label htmlFor='first_name' >First Name</label>
                        <input type='text' name='first_name' className='form-control' placeholder='Enter First Name' value={value.first_name} onChange={e=>setValue({...value, first_name: e.target.value})}/>
                    </div>
                    <div className='mb-2'>
                        <label htmlFor='last_name' >Last Name</label>
                        <input type='text' name='last_name' className='form-control' placeholder='Enter Last Name' value={value.last_name} onChange={e=>setValue({...value, last_name: e.target.value})}/>
                    </div>
                    <div className='mb-2'>
                        <label htmlFor='email' >Email</label>
                        <input type='email' name='email' className='form-control' placeholder='Enter Email' value={value.email} onChange={e=>setValue({...value, email: e.target.value})}/>
                    </div>
                    <div className='mb-2'>
                        <label htmlFor='gender' >Gender</label>
                        <input type='text' name='gender' className='form-control' placeholder='Enter Your Gender' value={value.gender} onChange={e=>setValue({...value, gender: e.target.value})}/>
                    </div>
                    <div className='mb-2'>
                        <label htmlFor='job' >Job</label>
                        <input type='text' name='job' className='form-control' placeholder='Enter Job' value={value.job} onChange={e=>setValue({...value, job: e.target.value})}/>
                    </div>
                    <button className='btn btn-success'>Update</button>
                    <Link to='/' className='btn btn-danger ms-2'>Cancel</Link>
                </form>
            </div>
        </div>
    );
}
export default UpdateComponent;