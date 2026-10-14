// Address map of the exe (idea: wasdhjklxyz/lbtvg and opensaga.dev progress pages). Reads map-data.json (browser-next/tools/update_function_counts.py):
// every game function in address order, one row per 16 KB of code, each block as wide as the function is long, coloured by state.
// Scroll to zoom (around the pointer), drag to pan, double-click or the reset button to fit; hover for details, click copies the address;
// filters by state, search by name or address, optional outlines around runs of functions of one class.
const ROW = 16384;
export const STATES = {
  P: { label: "ported into the game", color: "#3fb950" },
  V: { label: "decompiled, not ported", color: "#d29922" },
  D: { label: "claimed in the docs, no kept result", color: "#8a6d3b" },
  Q: { label: "queued for the agents", color: "#4a7fc1" },
  U: { label: "unassigned (SEH, jump table, large)", color: "#4b5059" },
};
const hex = (a) => a.toString(16).padStart(6, "0");
const esc = (s) => String(s).replace(/[<>&"]/g, "");

export async function mountMap(box, url = new URL("map-data.json", import.meta.url)) {
  if (!box) return;
  box.innerHTML = `<div class="maphead"><h2>ADDRESS MAP</h2><p class="src">All game code of the exe in address order, one row per 16 KB; each block is a function, as wide as it is long. Dark gaps are bytes that are not in a function. Scroll to zoom, drag to pan, double-click to fit. Hover for details, click to copy the address.</p></div>
    <div class="mapctl"><input type="search" class="mapq" placeholder="search a name or address, e.g. 5a1030 or DieByForce" autocomplete="off">
    ${Object.entries(STATES).map(([k, v]) => `<button class="chip" type="button" data-k="${k}" aria-pressed="true"><span class="dot" style="background:${v.color}"></span>${v.label}</button>`).join("")}
    <button class="chip" type="button" data-act="cls" aria-pressed="false">class outlines</button><button class="chip" type="button" data-act="reset">reset view</button></div>
    <canvas class="mapcv" aria-label="Address map of the exe"></canvas><div class="maptip"></div><p class="fine mapsum"></p>`;
  let d;
  try { d = await (await fetch(url)).json(); } catch { box.querySelector(".mapsum").textContent = "map data not found: run python3 browser-next/tools/update_function_counts.py"; return; }
  const F = d.functions, C = d.classes || [], [LO, HI] = d.text, rows = Math.ceil((HI - LO) / ROW);
  const cv = box.querySelector(".mapcv"), ctx = cv.getContext("2d"), tip = box.querySelector(".maptip"), q = box.querySelector(".mapq");
  const show = { P: true, V: true, D: true, Q: true, U: true }; let query = "", W = 0, VH = 520, LEFT = 46, hl = -1, outlines = false;
  // view: screen = (world * scale) - offset, world x in 0..1 across a row, world y in rows
  let zx = 1, zy = 1, ox = 0, oy = 0;
  const counts = {}, bytes = {};
  for (const f of F) { counts[f[2]] = (counts[f[2]] || 0) + 1; bytes[f[2]] = (bytes[f[2]] || 0) + f[1]; }
  box.querySelector(".mapsum").textContent = `${F.length.toLocaleString("en-US")} functions, ${d.total.toLocaleString("en-US")} bytes; ` + Object.entries(STATES).map(([k, v]) => `${v.label}: ${(counts[k] || 0).toLocaleString("en-US")} (${(100 * (bytes[k] || 0) / d.total).toFixed(1)}% of the code)`).join("; ") + `. Generated ${d.generated}.`;
  const match = (f) => !query || hex(f[0]).includes(query.replace(/^0x/i, "").toLowerCase()) || (f[3] || "").toLowerCase().includes(query);
  const fitY = () => VH / rows;                                  // screen pixels per row when fitted
  const reset = () => { zx = 1; zy = 1; ox = 0; oy = 0; draw(); };
  const clamp = () => { const pw = W - LEFT; zx = Math.min(Math.max(zx, 1), 60); zy = Math.min(Math.max(zy, 1), 60);
    ox = Math.min(Math.max(ox, 0), pw * zx - pw); oy = Math.min(Math.max(oy, 0), fitY() * rows * zy - VH); };
  const sx = (xf) => LEFT + xf * (W - LEFT) * zx - ox, sy = (r) => r * fitY() * zy - oy;
  function draw() {
    const dpr = window.devicePixelRatio || 1; W = Math.max(480, box.clientWidth); clamp();
    cv.width = W * dpr; cv.height = VH * dpr; cv.style.width = W + "px"; cv.style.height = VH + "px"; ctx.setTransform(dpr, 0, 0, dpr, 0, 0);
    ctx.fillStyle = "#101214"; ctx.fillRect(0, 0, W, VH);
    const rh = fitY() * zy, gap = rh > 5 ? 1 : 0;
    const r0 = Math.max(0, Math.floor(oy / rh)), r1 = Math.min(rows - 1, Math.ceil((oy + VH) / rh));
    ctx.fillStyle = "#1b1e22"; for (let r = r0; r <= r1; r += 1) ctx.fillRect(LEFT, sy(r) + gap, W - LEFT, Math.max(1, rh - 2 * gap));
    ctx.fillStyle = "#8b949e"; ctx.font = "9px monospace"; const every = Math.max(1, Math.ceil(11 / rh));
    for (let r = r0; r <= r1; r += every) ctx.fillText((LO + r * ROW).toString(16), 2, sy(r) + Math.min(8, rh));
    const lastClass = { v: -2 };
    for (let i = 0; i < F.length; i += 1) {
      const f = F[i]; if (!show[f[2]]) continue;
      if (f[0] + f[1] < LO + r0 * ROW || f[0] > LO + (r1 + 1) * ROW) continue;
      for (let a = f[0], left = f[1]; left > 0;) { // a function can straddle a row end
        const o = a - LO, r = Math.floor(o / ROW), room = ROW - (o % ROW), n = Math.min(left, room), xf = (o % ROW) / ROW;
        const x = sx(xf), w = Math.max(1, n / ROW * (W - LEFT) * zx), y = sy(r);
        if (y + rh >= 0 && y <= VH && x + w >= LEFT && x <= W) {
          ctx.globalAlpha = match(f) ? 1 : 0.12; ctx.fillStyle = STATES[f[2]].color; ctx.fillRect(Math.max(x, LEFT), y + gap, Math.min(w, x + w - LEFT), Math.max(1, rh - 2 * gap));
          if (outlines && f[4] >= 0 && rh > 4 && w > 2) { ctx.globalAlpha = .9; ctx.fillStyle = "#000"; ctx.fillRect(Math.max(x, LEFT), y + gap, 1, Math.max(1, rh - 2 * gap)); }
          if (i === hl) { ctx.globalAlpha = 1; ctx.strokeStyle = "#fff"; ctx.strokeRect(x - .5, y + .5, w + 1, Math.max(2, rh - 1)); }
        }
        a += n; left -= n;
      }
    }
    ctx.globalAlpha = 1;
  }
  const find = (ev) => { const b = cv.getBoundingClientRect(), x = ev.clientX - b.left, y = ev.clientY - b.top; if (x < LEFT) return -1;
    const rh = fitY() * zy, r = Math.floor((y + oy) / rh); if (r < 0 || r >= rows) return -1;
    const xf = (x - LEFT + ox) / ((W - LEFT) * zx), addr = LO + r * ROW + Math.floor(xf * ROW); let lo = 0, hi = F.length - 1, best = -1;
    while (lo <= hi) { const m = (lo + hi) >> 1; if (F[m][0] <= addr) { best = m; lo = m + 1; } else hi = m - 1; }
    return best >= 0 && addr < F[best][0] + F[best][1] && show[F[best][2]] ? best : -1; };
  let drag = null;
  cv.addEventListener("mousedown", (ev) => { drag = { x: ev.clientX, y: ev.clientY, ox, oy, moved: false }; });
  window.addEventListener("mouseup", () => { drag = null; });
  cv.addEventListener("mousemove", (ev) => {
    if (drag) { const dx = ev.clientX - drag.x, dy = ev.clientY - drag.y; if (Math.abs(dx) + Math.abs(dy) > 3) drag.moved = true; if (drag.moved) { ox = drag.ox - dx; oy = drag.oy - dy; tip.style.display = "none"; draw(); return; } }
    const i = find(ev); if (i !== hl) { hl = i; draw(); } if (i < 0) { tip.style.display = "none"; return; }
    const f = F[i]; tip.innerHTML = `<b>${f[3] ? esc(f[3]) + "</b><br>0x" + hex(f[0]) : "0x" + hex(f[0]) + "</b>"} · ${f[1]} bytes${f[4] >= 0 ? " · class " + esc(C[f[4]]) : ""}<br>${STATES[f[2]].label}`; tip.style.display = "block";
    const b = box.getBoundingClientRect(); tip.style.left = Math.min(ev.clientX - b.left + 14, b.width - 260) + "px"; tip.style.top = ev.clientY - b.top + 16 + "px"; });
  cv.addEventListener("mouseleave", () => { hl = -1; tip.style.display = "none"; draw(); });
  cv.addEventListener("click", (ev) => { if (drag && drag.moved) return; const i = find(ev); if (i >= 0) navigator.clipboard?.writeText("0x" + hex(F[i][0])).catch(() => {}); });
  cv.addEventListener("dblclick", reset);
  cv.addEventListener("wheel", (ev) => { ev.preventDefault(); const b = cv.getBoundingClientRect(), px = ev.clientX - b.left - LEFT, py = ev.clientY - b.top, k = Math.exp(-ev.deltaY * 0.0015);
    const wx = (px + ox) / zx, wy = (py + oy) / zy; zx *= k; zy *= k; clamp(); ox = wx * zx - px; oy = wy * zy - py; draw(); }, { passive: false });
  for (const b of box.querySelectorAll(".chip")) b.addEventListener("click", () => {
    if (b.dataset.act === "reset") return reset();
    if (b.dataset.act === "cls") { outlines = !outlines; b.setAttribute("aria-pressed", String(outlines)); return draw(); }
    const k = b.dataset.k; show[k] = !show[k]; b.setAttribute("aria-pressed", String(show[k])); draw(); });
  q.addEventListener("input", () => { query = q.value.trim().toLowerCase(); draw(); });
  window.addEventListener("resize", draw); draw();
}
