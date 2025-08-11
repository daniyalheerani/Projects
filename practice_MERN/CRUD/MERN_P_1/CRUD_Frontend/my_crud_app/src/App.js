import './App.css';
import { BrowserRouter, Routes, Route } from 'react-router-dom';
import 'bootstrap/dist/css/bootstrap.min.css';


import HomeComponent from './components/HomeComponent.jsx';
import CreateComponent from './components/CreateComponent.jsx';
import UpdateComponent from './components/UpdateComponent.jsx';
import ReadComponent from './components/ReadComponent.jsx';


const App = () => {
  return (
    <BrowserRouter className="App">
      <Routes>
        <Route path='/' element={<HomeComponent/>}></Route>
        <Route path='/create' element={<CreateComponent />}></Route>
        <Route path='/update/:id' element={<UpdateComponent />}></Route>
        <Route path='/read/:id' element={<ReadComponent />}></Route>
      </Routes>
    </BrowserRouter>
  );
};

export default App;
