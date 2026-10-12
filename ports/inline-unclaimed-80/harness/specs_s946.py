"""specs_s946.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): the walk at 0x438200. The object at self+0x19 (null 15%) has a
logging vtable: slot +0x4c writes a fixed word to its out-pointer and resets the walk; slot +0x5c takes the out-pointer (a stack
address, logged as 'stk'), writes a flag there, and returns the next node from a per-case list. The list is 1..4 nodes long
(the last flag 0), and 20% of cases have a first flag of 0 (the loop is skipped). Each node is null (15%), a buffer whose first
dword is zero (45%), or a buffer with a nonzero dword (40%); a write at node+0x42 lands inside the 0x60-byte buffer."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _walk(c):
    import pe_emu

    def nostk(v):
        return 'stk' if isinstance(v, int) and pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= v < pe_emu.STACK_TOP else v

    st = {'i': 0}
    if c.rng.random() < 0.2:
        seq = [(0, 0)]
    else:
        n = c.rng.randint(1, 4)
        seq = []
        for k in range(n):
            r = c.rng.random()
            buf = _rnd(c, 0x60)
            if r < 0.15:
                node = 0
            else:
                node = buf
                if r < 0.6:
                    c.emu.w32(buf, 0)
            seq.append((node, 1 if k < n - 1 else 0))

    def h(name, off, n, impl):
        def f(e, r):
            args = [e.arg32(k) for k in range(n)]
            e.calllog.append((name, off, e.reg('ecx'), tuple(nostk(a) for a in args)))
            eax, st0 = impl(e, args)
            e.ret(eax=eax, argbytes=4 * n)
        return f

    def impl4c(e, args):
        st['i'] = 0
        e.w32(args[0], 0x1234)
        return (0, None)

    def impl5c(e, args):
        i = st['i']
        st['i'] += 1
        node, flag = seq[i] if i < len(seq) else (0, 0)
        e.w32(args[0], flag)
        return (node, None)

    vt = c.emu.fake_vtable('ZGroupWalk', 24, {0x4c: h('ZGroupWalk', 0x4c, 1, impl4c),
                                              0x5c: h('ZGroupWalk', 0x5c, 1, impl5c)})
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, vt)
    self_o = _rnd(c, 0x40)
    c.emu.w32(self_o + 0x19, 0 if c.rng.random() < 0.15 else obj)
    return [self_o]


S(0x438200, 'walk over self+0x19 (unknown) thiscall', 'thiscall', None, ret=None, gen=_walk,
  note='unclaimed-80 gap band; slot +0x4c and +0x5c on the object at self+0x19; out-pointer on the stack')
