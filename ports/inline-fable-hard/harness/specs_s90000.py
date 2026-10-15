"""specs_s90000.py - hard trial (fable) batch 90000: 0x578f30 ZControllerA::Init2().
Engine object: slot 0xbc -> input device (slots 0xb8/0xc0 return a bool in al, upper bytes random), slot 0x190 -> formatter whose slot 0x198
is a cdecl sprintf stand-in (writes a string that names the format and index into the caller's stack buffer, logs (y, fmt, idx));
[eng+0x9b] -> settings via slot 0x134: slot 0x88 (name, &int) writes a dword, slot 0x90 (buf, &bool) logs the buffer text and writes one byte,
slot 0x68 (buf, v, 0) logs text + v (low byte only: the exe pushes a dword local of which only the low byte was ever written), slot 0x5c, slot 0x4c.
The four small direct callees (verified elsewhere) and 0x563a50 are hooked; their bool argument is logged as its low byte for the same reason."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, _HOOKED


def _cstr(em, p, limit=0x200):
    s = b''
    while len(s) < limit:
        ch = em.rbytes(p, 1)
        if ch == b'\0':
            break
        s += ch
        p += 1
    return s


def _g578f30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg('eax'))
    bools = [r.choice([0, 1, 1, 0xff, r.getrandbits(8)]) for _ in range(32)]
    rets = [r.getrandbits(32) for _ in range(64)]
    cnt = {'fmt': 0, 'z90': 0, 'ret': 0}

    def nxt(k):
        v = rets[cnt['ret'] % len(rets)]
        cnt['ret'] += 1
        return v

    def sprintf(em, res):
        a = [em.arg32(i) for i in range(4)]
        k = cnt['fmt']
        cnt['fmt'] += 1
        s = b'S%x_%d_%d_' % (a[2], a[3], k)
        s = (s + bytes(r.randint(1, 255) for _ in range(r.choice([0, 3, 20, 0x3f - len(s)]))))[:0x3f] + b'\0'
        em.wbytes(a[1], s)
        em.calllog.append(('fmt', a[0], a[2], a[3]))
        em.ret(eax=len(s) - 1, argbytes=0)

    def z88(em, res):   # read int setting (name, &out)
        em.calllog.append(('z88', em.reg('ecx'), em.arg32(0)))
        em.w32(em.arg32(1), r.choice([0, 0, 0, 1, 0x100, r.getrandbits(32)]))
        em.ret(eax=nxt(0), argbytes=8)

    def z90(em, res):   # read bool setting (buf, &out byte)
        k = cnt['z90']
        cnt['z90'] += 1
        em.calllog.append(('z90', em.reg('ecx'), _cstr(em, em.arg32(0))))
        em.wbytes(em.arg32(1), bytes([bools[k % len(bools)]]))
        em.ret(eax=nxt(0), argbytes=8)

    def z68(em, res):   # write setting (buf, v, 0): v is a bool pushed as a dword local, only its low byte is defined
        em.calllog.append(('z68', em.reg('ecx'), _cstr(em, em.arg32(0)), em.arg32(1) & 0xff, em.arg32(2)))
        em.ret(eax=nxt(0), argbytes=12)

    def boolhook(tag):
        def h(em, rr):
            em.calllog.append((tag, em.reg('ecx'), em.arg32(0) & 0xff))
            em.ret(eax=nxt(0), argbytes=4)
        return h
    for a, t in ((0x579a60, 'a60'), (0x579b20, 'b20'), (0x579bd0, 'bd0'), (0x579ca0, 'ca0')):
        e.hook(a, boolhook(t))
        _HOOKED.add(a)
    hook_rec(c, 0x563a50, 0, this=True, ret=lambda em, k: nxt(0))
    y = obj(c, 0x20, {0x198: e.stub_fn('sprintf', sprintf)})
    z = obj(c, 0x20, {0x88: e.stub_fn('z88', z88), 0x90: e.stub_fn('z90', z90), 0x68: e.stub_fn('z68', z68),
                      0x5c: pystub(c, 3, this=True, ret=lambda em, k: nxt(0))})
    dev = obj(c, 0x20, {0xb8: pystub(c, 0, this=True, ret=lambda em, k: (nxt(0) & ~0xff) | bools[(k + 7) % 32]),
                        0xc0: pystub(c, 0, this=True, ret=lambda em, k: (nxt(0) & ~0xff) | bools[(k + 11) % 32])})
    sysobj(c, slots={0x190: pystub(c, 0, this=True, ret=y), 0xbc: pystub(c, 0, this=True, ret=dev)},
           table_slots={0x134: pystub(c, 0, this=True, ret=z), 0x4c: pystub(c, 1, this=True, ret=lambda em, k: nxt(0))},
           table_size=0x140)
    # the controller: vtable slot 0x64(8); fields 0x44 (object id), 0x94 (profile object, never null: the end stores through it), 0x194 (index)
    E = obj(c, 0x200, {0x64: pystub(c, 1, this=True)})
    e.w32(E + 0x194, r.choice([0, 1, 2, 3, 3, 4, 7, 0xffffffff, r.getrandbits(32)]))
    p = e.alloc(0x132c0, 4)
    e.wbytes(p + 0x1038, bytes(r.getrandbits(8) for _ in range(8)))
    e.wbytes(p + 0x103c, bytes([r.choice([0, 0, 1, 0xff, r.getrandbits(8)])]))
    e.wbytes(p + 0x103f, bytes([r.choice([0, 0, 1, 0xff, r.getrandbits(8)])]))
    e.wbytes(p + 0x132a8, bytes(r.getrandbits(8) for _ in range(16)))
    e.w32(E + 0x94, p)
    return [E]


S(0x578f30, 'GUESS ZControllerA::Init2', 'thiscall', None, ret=None, gen=_g578f30, note='batch90000')
