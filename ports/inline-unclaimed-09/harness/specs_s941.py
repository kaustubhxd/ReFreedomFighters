"""specs_s941.py - unclaimed-09 batch 33 (docs/20-unclaimed-09.md, claim 35): ZRunParamAnim::Run(TIMETYPE).

The object is 0x200 random bytes (fields used up to +0xc0). Its list at +0xc is a fake vtable with slots 0x4c (begin; logs)
and 0x5c (next; hands out nodes in order and writes the flag). A node is a 0x20-byte heap object: +0 step 8, +4 a value that is one of
0x100000, 0x100001, 0x100002, 0x100003, 0xfff00000 in 60% of cases (n4 = value + 0xffefffff mod 2^32; the interpolation test
n4 <= 1 holds for values 0x100001 and 0x100002; 0x100003 gives n4 = 2 and does not interpolate), +8 a key pointer into a key buffer (int32 keys in
[-300, 300], 8-byte steps), +0xc the buffer end. The key buffer has 0x10 bytes of padding before the keys so that the cursor's
previous entry stays inside it. this+8 is odd (so (this+8) << 20 is never zero: no division by zero in the CRT helper), and
the byte at +0xbc is 0 or 1 at random. The 64-bit helper 0x634380 is the original code (not stubbed)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng
    nodes_n = rng.randint(1, 3)
    nodes = []
    buf = _rnd(c, 0x210)
    data = buf + 0x10
    for j in range(nodes_n):
        node = _rnd(c, 0x20)
        e.w32(node + 0, 8)
        e.w32(node + 4, rng.choice([0x100000, 0x100001, 0x100002, 0x100003, 0xfff00000]) if rng.random() < 0.6 else rng.getrandbits(32))
        e.w32(node + 8, data + 8 * rng.randint(1, 31))
        e.w32(node + 0xc, data + 0x100)
        nodes.append(node)
    for i in range(0, 0x100, 4):
        e.w32(data + i, rng.randint(-300, 300) & 0xffffffff)

    seq = {'i': 0}
    flag_val = {'v': 0}

    def h4c(e2, r):
        e2.calllog.append(('Begin4c',))
        e2.ret(eax=0, argbytes=4)

    def h5c(e2, r):
        flagp = e2.arg32(0)
        i = seq['i']
        seq['i'] = i + 1
        if i < nodes_n:
            e2.w32(flagp, 1)
            e2.calllog.append(('Next5c', i))
            e2.ret(eax=nodes[i], argbytes=4)
        else:
            e2.w32(flagp, 0)
            e2.calllog.append(('Next5c', 'end'))
            e2.ret(eax=0, argbytes=4)

    vt = e.fake_vtable('rpa_list', 0x20, {0x4c: h4c, 0x5c: h5c})
    this = _rnd(c, 0x200)
    e.w32(this + 0xc, vt)
    e.w32(this + 8, rng.getrandbits(32) | 1)
    e.w8(this + 0xbc, rng.getrandbits(1))
    e.w32(this + 0xbd, _fl(rng))
    b8 = _fl(rng)
    e.w32(this + 0xb8, b8)
    time = rng.randint(-1000, 1000)
    # Make the early-return equality case reachable: this+8 == (P >> 20) when that value is odd (so it is non-zero shifted).
    import struct as _st
    k1 = _st.unpack('<f', bytes(e.rbytes(0x678620, 4)))[0]
    fl = _st.unpack('<f', _st.pack('<f', _st.unpack('<f', _st.pack('<I', b8))[0] * k1))[0]
    if -2.0**31 < fl < 2.0**31:
        t32 = int(fl)
        a = (t32 * time) >> 20
        if -2**31 <= a < 2**31 and (a & 1) and rng.random() < 0.5:
            e.w32(this + 8, a & 0xffffffff)
    return [this, time & 0xffffffff]


def _fl(rng):
    import struct
    return struct.unpack('<I', struct.pack('<f', rng.uniform(-3.0, 3.0)))[0]


S(0x4e6f80, 'ZRunParamAnim::Run (unknown) thiscall', 'thiscall', None, ret='st0', gen=_gen,
  note='unclaimed-09 b33; list vt 0x4c/0x5c GUESS recording stubs; 0x634380 original code')
