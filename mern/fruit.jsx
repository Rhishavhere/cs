import { useState, useEffect } from "react";
import axios from "axios";

function App() {
  const [form, setForm] = useState({});
  const [fruits, setFruits] = useState([]);

  const handleForm = (e) => {
    setForm({ ...form, [e.target.name]: e.target.value });
  };

  const getFruits = async () => {
    let res = await axios.get("http://localhost:8080/data");
    setFruits(res.data);
  };

  const handleSubmit = async (e) => {
    e.preventDefault();

    await axios.post(
      "http://localhost:8080/demo",
      form
    );

    getFruits();
  };

  useEffect(() => {
    getFruits();
  }, []);

  return (
    <div>
      <h2>Fruit Details</h2>

      <form onSubmit={handleSubmit}>
        Fruit Name :
        <input name="fname" onChange={handleForm} />
        <br />

        Price :
        <input name="price" onChange={handleForm} />
        <br />

        <input type="submit" />
      </form>

      <table border="1">
        <tbody>
          {fruits.map((f, i) => (
            <tr key={i}>
              <td>{f.fname}</td>
              <td>{f.price}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}

export default App;