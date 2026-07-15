import { useState, useEffect } from "react";

function App() {
  const [users, setUsers] = useState([]);

  useEffect(() => {
    getUsers();
  }, []);

  const getUsers = async () => {
    let res = await fetch("https://jsonplaceholder.typicode.com/users");
    let d = await res.json();
    setUsers(d);
  };

  return (
    <div>
      <h2>User Data</h2>

      <table border="1">
        <thead>
          <tr>
            <th>Name</th>
            <th>Email</th>
          </tr>
        </thead>

        <tbody>
          {users.map(user => (
            <tr key={user.id}>
              <td>{user.name}</td>
              <td>{user.email}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}

export default App;