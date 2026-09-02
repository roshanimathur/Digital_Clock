<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<title>Digital Clock</title>
<style>
  :root {
    --bg: #0d1117;
    --panel: #111726;
    --digit: #7ee0c3;
    --digit-dim: #1f3b34;
    --label: #6b7787;
  }

  * { box-sizing: border-box; }

  body {
    margin: 0;
    height: 100vh;
    display: flex;
    align-items: center;
    justify-content: center;
    background: var(--bg);
    font-family: 'Segoe UI', system-ui, sans-serif;
  }

  .clock-panel {
    background: var(--panel);
    border-radius: 18px;
    padding: 48px 64px;
    box-shadow: 0 0 40px rgba(126, 224, 195, 0.08), inset 0 0 0 1px rgba(255,255,255,0.04);
    text-align: center;
  }

  #time {
    font-family: 'Consolas', 'Courier New', monospace;
    font-size: 5rem;
    font-weight: 600;
    letter-spacing: 4px;
    color: var(--digit);
    text-shadow: 0 0 12px rgba(126, 224, 195, 0.5);
  }

  #time span.colon {
    animation: blink 1s steps(1) infinite;
    color: var(--digit-dim);
  }

  #date {
    margin-top: 12px;
    font-size: 0.95rem;
    letter-spacing: 2px;
    color: var(--label);
  }

  @keyframes blink {
    50% { opacity: 0; }
  }
</style>
</head>
<body>

  <div class="clock-panel">
    <div id="time">00:00:00</div>
    <div id="date">Loading date...</div>
  </div>

  <script>
    function pad(n) {
      return n.toString().padStart(2, '0');
    }

    function updateClock() {
      const now = new Date();

      const hours = pad(now.getHours());
      const minutes = pad(now.getMinutes());
      const seconds = pad(now.getSeconds());

      document.getElementById('time').innerHTML =
        hours + '<span class="colon">:</span>' +
        minutes + '<span class="colon">:</span>' +
        seconds;

      const options = { weekday: 'long', year: 'numeric', month: 'long', day: 'numeric' };
      document.getElementById('date').textContent = now.toLocaleDateString(undefined, options);
    }

    updateClock();
    setInterval(updateClock, 1000);
  </script>

</body>
</html>
