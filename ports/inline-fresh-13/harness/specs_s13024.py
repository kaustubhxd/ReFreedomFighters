"""specs_s13024.py - fresh-13 batch 24: 0x56d950 CMultiplayerKOTH::UpdatePlayerStatus. Thiscall, no args.
Text table (db+0xae4) slot 0 (2 args) returns a per-key value, logged; (*0x7003a0) slot 0x4c returns a random mask
(sometimes with high bits); sys slot 0x190 returns the formatter whose cdecl slot 0x198 writes a deterministic text
(a function of its arguments) into the buffer and logs its arguments (6 words; the 6th only matters for the 6-word
form). Widgets: slot 0x284 logs the text only after the formatter ran in this call (otherwise the exe passes
uninitialised stack), slot 0x24c logs the 3 colour words. Bytes this+0x19c.. / +0x1a0.. random."""
from pilot import S
from fr13 import Log, loghook, logstub, vobj, rnd, clear_hooks, flush, HOOKED  # noqa: F401


def _gen(c):
    r = c.rng
    clear_hooks(c)
    log = Log(c, cap=40, width=8)

    def _code(fn):
        a = c.emu.alloc(16, 16)
        c.emu.wbytes(a, b'\xc3' * 16)
        HOOKED.add(a)
        c.emu.hook(a, fn)
        return a
    vals = {}

    def _tr(e):
        k = e.r32(e.reg('esp') + 8)
        return vals.setdefault(k, (k * 2654435761) & 0xffffffff)
    trv = vobj(c, 0x10, {0: logstub(c, log, 2, 1, ret=_tr)})
    db = c.emu.alloc(0xae8, 4)
    c.emu.w32(db + 0xae4, trv)
    st = {'fmt': 0}

    def _fmt(e, rr):
        sp = e.reg('esp')
        a = [e.r32(sp + 4 + 4 * k) for k in range(6)]
        log.put(e, [2] + (a[2:6] if a[2] == 0x6a80f0 else a[2:5]))   # the 5-word form leaves word 6 unset
        txt = ('%08x%08x%08x' % (a[2], a[3], a[4])).encode() + b'\0'
        e.wbytes(a[1], txt)
        st['fmt'] = 1
        e.ret(eax=0)
    fobj = vobj(c, 0x1a0, {0x198: _code(_fmt)})
    sysobj = vobj(c, 0xa0, {0x190: logstub(c, log, 0, 3, ret=fobj)})
    c.emu.w32(sysobj + 0x9b, db)
    c.emu.w32(0x70039c, sysobj)
    mp = vobj(c, 0x50, {0x4c: logstub(c, log, 0, 4, ret=r.getrandbits(4) | (r.getrandbits(28) << 4 if r.random() < 0.3 else 0))})
    c.emu.w32(0x7003a0, mp)

    def _text(e, rr):
        p = e.r32(e.reg('esp') + 4)
        log.put(e, [5, e.reg('ecx')] + ([e.r32(p + 4 * k) for k in range(6)] if st['fmt'] else []))
        e.ret(eax=0, argbytes=4)
    a284 = _code(_text)
    a24c = logstub(c, log, 1, 6, deref={0: 3})
    me = rnd(c, 0x1a8)
    for i in range(4):
        w = vobj(c, 0x10, {0x284: a284, 0x24c: a24c})
        c.emu.w32(me + 0x18c + 4 * i, w)
        c.emu.w8(me + 0x19c + i, r.choice([0, 1, 0x80]))
        c.emu.w8(me + 0x1a0 + i, r.choice([0, 1, 0x80]))
    flush(c)
    return [me]


S(0x56d950, 'CMultiplayerKOTH::UpdatePlayerStatus', 'thiscall', None, ret=None, gen=_gen,
  note='fresh13 batch13024; text table, formatter, widgets logged; text logged only once formatted')
