import { useState, useEffect } from "react";

function App() {
  const [form, setForm] = useState({});
  const [users, setUsers] = useState([]);

  const handleChange = (e) => {
    setForm({ ...form, [e.target.name]: e.target.value });
  };

  const getUsers = async () => {
    let res = await fetch("http://localhost:8080/data");
    let data = await res.json();
    setUsers(data);
  };

  const handleSubmit = async (e) => {
    e.preventDefault();

    await fetch("http://localhost:8080/demo", {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify(form),
    });

    getUsers();
  };

  useEffect(() => {
    getUsers();
  }, []);

  return (
    <div>
      <h2>Student Details</h2>

      <form onSubmit={handleSubmit}>
        <input name="usn" placeholder="USN" onChange={handleChange} /> <br/>
        <input name="name" placeholder="Name" onChange={handleChange} /> <br/>
        <input name="sem" placeholder="Sem" onChange={handleChange} /> <br/>
        <input name="year" placeholder="Year" onChange={handleChange} /> <br/>
        <button>Submit</button>
      </form>

      <table>
        <tbody>
          {users.map((u, i) => (
            <tr key={i}>
              <td>{u.usn}</td>
              <td>{u.name}</td>
              <td>{u.sem}</td>
              <td>{u.year}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}

export default App;