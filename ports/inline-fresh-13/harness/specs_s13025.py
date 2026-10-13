"""specs_s13025.py - fresh-13 batch 25: 0x4b0350 CCutSequenceEvent::GetRootObject(REFTAB*, REFTAB*, const char*).
Thiscall, ret 0xc. Three REFTABs (a, b, this+0x4c -> +0x18; each null in some inputs) are Python iterators: slot 0x4c
resets it[1], slot 0x5c returns the next id and sets it[0] (1 valid / 0 done; a random id when done), logged by tag
and index only. db slot 0x54 maps ids to geoms (or 0). Geom names (+0x54 -> +4) come from a pool with null
("<NONAME>"), the searched name from the same pool, so _stricmp (Python stub) matches often; bit 10 of +0x3c random.
0x4db9a0 (1 arg) answers a per-(object, id) random bool; children via (geom+0x54)+0x54 and GetPrev 0x4db520 (map)
with type flags 0x100000 set or not."""
from pilot import S
from fr13 import Log, loghook, logstub, vobj, rnd, clear_hooks, flush, HOOKED  # noqa: F401
from specs_s13022 import _cstr


def _gen(c):
    r = c.rng
    clear_hooks(c)
    log = Log(c, cap=64, width=4)

    def _code(fn):
        a = c.emu.alloc(16, 16)
        c.emu.wbytes(a, b'\xc3' * 16)
        HOOKED.add(a)
        c.emu.hook(a, fn)
        return a

    def sz(s):
        a = c.emu.alloc(len(s) + 1, 1)
        c.emu.wbytes(a, s + b'\0')
        return a
    pool = [sz(b'Root'), sz(b'root'), sz(b'Hero'), 0]
    name = r.choice([pool[0], pool[2], sz(b'<NONAME>')])
    prev = {}

    def child():
        n = rnd(c, 0x60)
        o = 0
        if r.random() < 0.85:
            o = rnd(c, 0x20)
            t = rnd(c, 0x30)
            c.emu.w32(t + 0x23, r.getrandbits(32) & ~0x100000 | r.choice([0, 0, 0x100000]))
            c.emu.w32(o + 0xc, t)
        c.emu.w32(n + 0x54, o)
        return n

    def geom():
        if r.random() < 0.1:
            return 0
        g = rnd(c, 0x60)
        info = rnd(c, 0x60)
        c.emu.w32(info + 4, r.choice(pool))
        q = 0
        for k in range(r.choice([0, 1, 2, 3])):
            n = child()
            prev[n] = q
            q = n
        c.emu.w32(info + 0x54, q)
        c.emu.w32(g + 0x54, info)
        c.emu.w32(g + 0x3c, r.getrandbits(32))
        return g
    ids = {}

    def table(tag):
        if r.random() < 0.15:
            return 0
        lst = []
        for k in range(r.choice([0, 1, 2, 3, 4])):
            i = r.getrandbits(32)
            ids[i] = geom()
            lst.append(i)
        junk = r.getrandbits(32)

        def _init(e, rr):
            e.w32(e.r32(e.reg('esp') + 4) + 4, 0)
            log.put(e, [tag])
            e.ret(eax=0, argbytes=4)

        def _next(e, rr):
            p = e.r32(e.reg('esp') + 4)
            k = e.r32(p + 4)
            e.w32(p + 4, k + 1)
            e.w32(p, 1 if k < len(lst) else 0)
            log.put(e, [tag + 1, k])
            e.ret(eax=lst[k] if k < len(lst) else junk, argbytes=4)
        return vobj(c, 0x10, {0x4c: _code(_init), 0x5c: _code(_next)})
    ta, tb, tc = table(10), table(20), table(30)
    db = vobj(c, 0x60, {0x54: logstub(c, log, 1, 1, ret=lambda e: ids.get(e.r32(e.reg('esp') + 4), 0))})
    sysobj = c.emu.alloc(0xa0, 4)
    c.emu.w32(sysobj + 0x9b, db)
    c.emu.w32(0x70039c, sysobj)
    acc = {}

    def _acc(e):
        k = (e.reg('ecx'), e.r32(e.reg('esp') + 4))
        if k not in acc:
            acc[k] = r2.pop() if r2 else 1
        return acc[k]
    r2 = [r.choice([0, 1, 1, 0x100]) for _ in range(40)]
    loghook(c, log, 0x4db9a0, 1, 2, ret=_acc)
    loghook(c, log, 0x4db520, 0, 3, ret=lambda e: prev.get(e.reg('ecx'), 0))

    def _stricmp(e, rr):
        sp = e.reg('esp')
        a, b = _cstr(e, e.r32(sp + 4)).lower(), _cstr(e, e.r32(sp + 8)).lower()
        e.ret(eax=(a > b) - (a < b))
    c.emu.stub_import('_stricmp', _stricmp)
    me = rnd(c, 0x60)
    if tc and r.random() < 0.9:
        cc = rnd(c, 0x20)
        c.emu.w32(cc + 0x18, tc)
        c.emu.w32(me + 0x4c, cc)
    else:
        cc = rnd(c, 0x20)
        c.emu.w32(cc + 0x18, 0)
        c.emu.w32(me + 0x4c, r.choice([0, cc]))
    flush(c)
    return [me, ta, tb, name]


S(0x4b0350, 'CCutSequenceEvent::GetRootObject', 'thiscall', None, ret='eax', gen=_gen,
  note='fresh13 batch13025; REFTAB iterators are Python hooks; _stricmp Python stub; 0x4db9a0 / GetPrev hooked')
