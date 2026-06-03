function Prime() {
  let p = [];

  for (let i = 2; i <= 100; i++) {
    let flag = true;

    for (let j = 2; j < i; j++) {
      if (i % j === 0) {
        flag = false;
        break;
      }
    }

    if (flag) p.push(i);
  }

  return (
    <div>
      <h3>Prime Numbers</h3>
      {p.map((n) => (
        <li>{n}</li>
      ))}
    </div>
  );
}

export default Prime;