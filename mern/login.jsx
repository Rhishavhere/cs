import { useState } from "react";
import axios from "axios";

function App() {
  const [form, setForm] = useState({});

  const handleForm = (e) => {
    setForm({ ...form, [e.target.name]: e.target.value });
  };

  const handleSubmit = async (e) => {
    e.preventDefault();

    let res = await axios.post(
      "http://localhost:8080/demo",
      form
    );

    alert(res.data);
  };

  return (
    <form onSubmit={handleSubmit}>
      Username :
      <input name="uname" onChange={handleForm} />
      <br />

      Password :
      <input type="password" name="pass" onChange={handleForm} />
      <br />

      <button>Login</button>
    </form>
  );
}

export default App;