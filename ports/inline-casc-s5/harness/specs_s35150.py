"""specs_s35150.py - 0x490120 (stdcall(name, kind) ret 8, ret='eax'). List at [0x7003bc]: 0..4 nodes (empty in 1/6) of 0x30 random bytes with a name pointer at +0, kind dword at +4 (equal to `kind` in 2/3, else 0..3), next at +0x14, and an unaligned name pointer at +0x1f; names from a small
case-varying word set; kind is 1 in half of the cases; _stricmp stubbed in Python (logs both strings). Logger at 0x700390: slot 0x20 (2 args) returns an object whose slot 0x30 is recorded (3 args, ECX = the vtable, caller-popped)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g490120(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    words = [b'btn', b'BTN', b'menu', b'x', b'Menu', b'']

    def mkstr():
        p = rnd(c, 0x10)
        e.wbytes(p, r.choice(words) + b'\0')
        return p
    kind = 1 if r.random() < 0.5 else r.choice([0, 2, 3, 0x100, r.getrandbits(32)])
    name = mkstr()
    nodes = []
    for _ in range(r.choice([0, 0, 1, 2, 3, 4]) if r.random() > 1 / 6 else 0):
        nd = rnd(c, 0x30)
        e.w32(nd, mkstr())
        e.w32(nd + 4, kind if r.random() < 2 / 3 else r.randint(0, 3))
        e.wbytes(nd + 0x1f, mkstr().to_bytes(4, 'little'))
        nodes.append(nd)
    for i, nd in enumerate(nodes):
        e.w32(nd + 0x14, nodes[i + 1] if i + 1 < len(nodes) else 0)
    e.w32(0x7003bc, nodes[0] if nodes else 0)

    def stricmp(em, res_):
        def rd(p):
            d = b''
            while len(d) < 32:
                b = bytes(em.rbytes(p + len(d), 1))
                if b == b'\0':
                    break
                d += b
            return d
        a, b = rd(em.arg32(0)), rd(em.arg32(1))
        em.calllog.append(('_stricmp', a, b))
        x, y = a.lower(), b.lower()
        em.ret(eax=0 if x == y else (1 if x > y else 0xffffffff))
    e.stub_import('_stricmp', stricmp)
    lg2 = obj(c, 0x20, {0x30: pystub(c, 3, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    return [name, kind]


S(0x490120, 'GUESS find registered entry by name and kind', 'stdcall', None, ret='eax', gen=_g490120, note='batch35150')
