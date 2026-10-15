"""specs_s95000.py - hard-function trial opus5: 0x479190 Load(stream) (407 instructions, 71 calls, C++ EH frame).

The stream is a fake object whose read slots (0x40/0x50 dword, 0x68 byte, 0x6c 12 bytes, 0x18 raw, 0x30, 0x48) are Python
stubs: each call is logged (slot, ECX, args; stack pointers masked) into a compared heap log, writes pseudo-random data
(from a per-case pool, indexed by the call number) through its out pointer, logs the SEH chain it sees (seh_log), and
returns one of three stream objects (same vtable) so every chained call must use the returned EAX.
"""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub, seh_chain, seh_log, HEAP_LO, HEAP_HI, STACK_MARK
import pe_emu

STK_LO = pe_emu.STACK_TOP - pe_emu.STACK_SIZE
STK_HI = pe_emu.STACK_TOP
WIDTH = {0x40: 4, 0x50: 4, 0x68: 1, 0x6c: 12, 0x48: 4}


def _writable(p, n):
    return (HEAP_LO <= p and p + n <= HEAP_HI) or (STK_LO <= p and p + n <= STK_HI)


def gen(c):
    clear_hooks(c)
    em = c.emu
    rng = c.rng
    em.w32(0x7003b0, pystub(c, 0, ret=rng.getrandbits(32)))   # assert hook (pitfall 2)
    seh_chain(c, rng.randrange(3))
    sehside = seh_log(c, depth=2)

    self_ = rnd(c, 0x790)
    pool = [rng.getrandbits(32) for _ in range(512)]
    zero_byte = rng.random() < 0.4          # the byte read into the 'has sub-object' flag (call 2 of slot 0x68) is 0
    nstreams = 3
    streams = [rnd(c, 0x20) for _ in range(nstreams)]
    picks = [rng.randrange(nstreams) for _ in range(512)]
    log = em.alloc(16 * 300 + 4, 4)
    cnt = log + 16 * 300
    st = {'n': 0, 'b': 0}

    def mask(v):
        return v if HEAP_LO <= v < HEAP_HI else (STACK_MARK if STK_LO <= v < STK_HI else v)

    def handler(off, nargs):
        def h(emu, r):
            n = st['n']
            st['n'] = n + 1
            ecx = emu.reg('ecx')
            args = [emu.arg32(i) for i in range(nargs)]
            row = log + 16 * min(n, 299)
            emu.w32(row, off)
            emu.w32(row + 4, ecx)
            emu.w32(row + 8, mask(args[0]) if nargs > 0 else 0)
            emu.w32(row + 12, args[1] if nargs > 1 else 0)
            emu.w32(cnt, n + 1)
            emu.calllog.append(('stream', off))
            sehside(emu)
            v = pool[n % 512]
            if off in WIDTH:
                w = WIDTH[off]
                p = args[0]
                if off == 0x68:
                    b = st['b']
                    st['b'] = b + 1
                    if b == 1 and zero_byte:
                        v = 0
                if _writable(p, w):
                    data = b''.join(pool[(n + k) % 512].to_bytes(4, 'little') for k in range(3))[:w]
                    if off == 0x68:
                        data = bytes([v & 0xff])
                    emu.wbytes(p, data)
            elif off == 0x18:
                p, size = args
                if _writable(p, min(size, 64)) and size:
                    emu.wbytes(p, b''.join(pool[(n + k) % 512].to_bytes(4, 'little') for k in range(16))[:min(size, 64)])
            if off in (0x40, 0x50, 0x68, 0x6c):
                e = streams[picks[n % 512]]
            elif off == 0x30:
                e = v
            else:
                e = rng_junk[n % 64]
            emu.ret(eax=e, argbytes=4 * nargs)
        return h

    rng_junk = [rng.getrandbits(32) for _ in range(64)]
    slots = {0x40: handler(0x40, 1), 0x50: handler(0x50, 1), 0x68: handler(0x68, 1), 0x6c: handler(0x6c, 1),
             0x18: handler(0x18, 2), 0x30: handler(0x30, 0), 0x48: handler(0x48, 1)}
    vt = em.fake_vtable('stream', 0x70 // 4, slots)
    for s in streams:
        em.w32(s, vt)

    # engine [0x70039c] + 0x9b (unaligned) -> object whose slot 0x58 maps an id (thiscall, 1 arg)
    eng = rnd(c, 0x100)
    sub = rnd(c, 0x10)
    vts = em.alloc(0x60, 4)
    em.w32(vts + 0x58, pystub(c, 1, ret=rng.getrandbits(32), this=True, side=sehside))
    em.w32(sub, vts)
    em.wbytes(eng + 0x9b, sub.to_bytes(4, 'little'))
    em.w32(0x70039c, eng)

    # callees: base Load, operator new (cdecl), sub-object constructor (thiscall, ret 4)
    hook_rec(c, 0x474770, 1, ret=rng.getrandbits(32), this=True, side=sehside)
    mem = 0 if rng.random() < 0.15 else rnd(c, 0x18)
    hook_rec(c, 0x41e290, 1, ret=mem, pop=0, side=sehside)
    built = mem if (mem == 0 or rng.random() < 0.75) else rnd(c, 0x18)
    if built:
        k = rng.randrange(5)
        c.emu.w32(built + 8, k)
        c.emu.w32(built + 0xc, rnd(c, 16 * k + 4))
        c.emu.w32(built + 0x10, rnd(c, 4 * k + 4))
    hook_rec(c, 0x476dc0, 1, ret=built, this=True, side=sehside)
    return [self_, streams[0]]


S(0x479190, 'GUESS ZObject::Load(stream)', 'thiscall', None, ret='al', gen=gen)
