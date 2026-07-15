import { BrowserRouter, Routes, Route, Link } from "react-router-dom";
import Prime from "./Prime";
import Cube from "./Cube";

function App() {
  return (
    <BrowserRouter>
      <Link to="/prime">Prime</Link> &nbsp;
      <Link to="/cube">Cube</Link>

      <Routes>
        <Route path="/prime" element={<Prime />} />
        <Route path="/cube" element={<Cube />} />
      </Routes>
    </BrowserRouter>
  );
}

export default App;