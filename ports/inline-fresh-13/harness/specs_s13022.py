"""specs_s13022.py - fresh-13 batch 22: 0x431a50 CConfiguration::AddKeyMapping(SActionOverride*). Thiscall, ret 4.
The list at this+0x84 is a Python list: slots 0x4c (it[0] = 0), 0x64 (next entry or 0), 0x44 (remove: logs the index)
and 4 (new node: logs its argument, returns a fresh 0xc0-byte buffer + 4). 0..4 entries whose names / contexts come
from small pools ("Fire" / "fire" / "Jump", context 0 / "Menu" / "menu" / "Game") so _stricmp (a Python stub) matches
often; keys copied from src or random. MYSTR c_str 0x4cc1d0 and MYSTR() 0x4cbeb0 run as exe code; operator= 0x4cbee0
(1 arg) and operator new 0x41e290 (cdecl, returns a pre-allocated buffer) are logged hooks."""
from pilot import S
from fr13 import Log, loghook, logstub, vobj, rnd, clear_hooks, flush, HOOKED  # noqa: F401


def _cstr(e, a):
    s = b''
    while True:
        b = bytes(e.mu.mem_read(a + len(s), 1))
        if b == b'\0':
            return s
        s += b


def _gen(c):
    r = c.rng
    clear_hooks(c)
    log = Log(c, cap=24, width=4)

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
    names = [sz(b'Fire'), sz(b'fire'), sz(b'Jump')]
    ctxs = [0, 0, sz(b'Menu'), sz(b'menu'), sz(b'Game')]
    keys = [r.getrandbits(32) for _ in range(5)]

    def ovr(same):
        o = rnd(c, 0xb4)
        c.emu.w32(o, r.choice(names))
        c.emu.w32(o + 0xaf, r.choice(ctxs))
        for k, off in enumerate((0x80, 0x84, 0x88, 0x8c, 0xa1)):
            c.emu.w32(off + o, keys[k] if same and r.random() < 0.9 else r.getrandbits(32))
        return o
    src = ovr(True)
    els = [ovr(True) for _ in range(r.choice([0, 1, 2, 3, 4]))]

    def _init(e, rr):
        e.w32(e.r32(e.reg('esp') + 4), 0)
        log.put(e, [1])
        e.ret(eax=0, argbytes=4)

    def _next(e, rr):
        p = e.r32(e.reg('esp') + 4)
        i = e.r32(p)
        e.w32(p, i + 1)
        log.put(e, [2, i])
        e.ret(eax=els[i] if i < len(els) else 0, argbytes=4)

    def _rem(e, rr):
        p = e.r32(e.reg('esp') + 4)
        log.put(e, [3, e.r32(p)])
        e.ret(eax=0, argbytes=4)
    node = rnd(c, 0xc0)

    def _new(e, rr):
        log.put(e, [4, e.r32(e.reg('esp') + 4)])
        e.ret(eax=node + 4, argbytes=4)
    vt = c.emu.alloc(0x68, 4)
    for off, fn in ((0x4c, _init), (0x64, _next), (0x44, _rem), (4, _new)):
        c.emu.w32(vt + off, _code(fn))
    me = rnd(c, 0xa0)
    c.emu.w32(me + 0x84, vt)

    def _stricmp(e, rr):
        sp = e.reg('esp')
        a, b = _cstr(e, e.r32(sp + 4)).lower(), _cstr(e, e.r32(sp + 8)).lower()
        e.ret(eax=(a > b) - (a < b))
    c.emu.stub_import('_stricmp', _stricmp)
    loghook(c, log, 0x4cbee0, 1, 5, ret=lambda e: e.reg('ecx'))
    buf = rnd(c, 16)
    loghook(c, log, 0x41e290, 1, 6, ret=buf, this=False, pop=False)
    flush(c)
    return [me, src]


S(0x431a50, 'CConfiguration::AddKeyMapping', 'thiscall', None, ret='eax', gen=_gen,
  note='fresh13 batch13022; list slots are Python hooks; _stricmp Python stub; MYSTR c_str / ctor run as exe code')
