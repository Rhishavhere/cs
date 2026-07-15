import { useState, useEffect } from "react";

function App() {
  const [data, setData] = useState([]);

  useEffect(() => {
    getData();
  }, []);

  const getData = async () => {
    let res = await fetch("https://dummy.restapiexample.com/api/v1/employees");
    let d = await res.json();
    setData(d.data);
  };

  return (
    <table style={{width: '100vw', textAlign:'center'}}>
      <thead>
        <tr>
          {data[0] &&
            Object.keys(data[0]).map(h => <th>{h}</th>)}
        </tr>
      </thead>

      <tbody>
        {data.map(row => (
          <tr>
            {Object.values(row).map(val => <td>{val}</td>)}
          </tr>
        ))}
      </tbody>
    </table>
  );
}

export default App;