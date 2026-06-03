function Cube() {
  let c = [];

  for (let i = 1; i * i * i < 100; i++) {
    c.push(i * i * i);
  }

  return (
    <div>
      <h3>Cubes</h3>
      {c.map((n) => (
        <li>{n}</li>
      ))}
    </div>
  );
}

export default Cube;